#include "pch.h"

#include "Core/Core.h"
#include "Core/Application.h"

#include <glad/glad.h>

//DBG cube
#include "Renderer/BufferLayout.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
unsigned int vertexArr;
DarknessEngine::OpenGLShader* shader;
DarknessEngine::OpenGLVertexBuffer* vertexBuff;
DarknessEngine::OpenGLIndexBuffer* indexBuff;


GLenum getGlType(const DarknessEngine::ShaderDataType& t) {
    switch (t)
    {
    case DarknessEngine::ShaderDataType::Float:
    case DarknessEngine::ShaderDataType::Float2:
    case DarknessEngine::ShaderDataType::Float3:
    case DarknessEngine::ShaderDataType::Float4:
    case DarknessEngine::ShaderDataType::Mat3:
    case DarknessEngine::ShaderDataType::Mat4:
        return GL_FLOAT;

    case DarknessEngine::ShaderDataType::Int:
    case DarknessEngine::ShaderDataType::Int2:
    case DarknessEngine::ShaderDataType::Int3:
    case DarknessEngine::ShaderDataType::Int4:
        return GL_INT;


    case DarknessEngine::ShaderDataType::Boolean:
        return GL_BOOL;
    }

    DE_ASSERT(false, "Unknown Shader data type");
    return 0;
}

//------------------------------------------------

namespace DarknessEngine{

#define BIND_EVENT_FUNC(func) std::bind(&Application::func, this, std::placeholders::_1)

    Application* Application::s_inst = nullptr;

    Application::Application(){
        DE_ASSERT(!s_inst, "Application instance already exist!");
        s_inst = this;

        m_window = std::unique_ptr<Window>(Window::create());
        m_window->setEventCallback(BIND_EVENT_FUNC(onEvent));

        m_imguiLayer = new ImGuiLayer();
        pushOverlay(m_imguiLayer);

        glGenVertexArrays(1, &vertexArr);
        glBindVertexArray(vertexArr);

        float vertices[8 * 7] =
        {
            // x       y       z          R      G       B        a
            -0.5f,  -0.5f,  -0.5f,      0.5f,  0.3f,   0.9f,    1.0f, // Vertex 0
            -0.5f,  -0.5f,   0.5f,      0.0f,  1.0f,   0.0f,    1.0f, // Vertex 1
            -0.5f,   0.5f,  -0.5f,      0.9f,  0.0f,   0.0f,    1.0f, // Vertex 2
            -0.5f,   0.5f,   0.5f,      1.0f,  0.7f,   0.0f,    1.0f, // Vertex 3
             0.5f,  -0.5f,  -0.5f,      1.0f,  0.0f,   1.0f,    1.0f, // Vertex 4
             0.5f,  -0.5f,   0.5f,      0.0f,  1.0f,   1.0f,    1.0f, // Vertex 5
             0.5f,   0.5f,  -0.5f,      1.0f,  0.3f,   1.0f,    1.0f, // Vertex 6
             0.5f,   0.5f,   0.5f,      1.0f,  0.5f,   0.5f,    1.0f  // Vertex 7
        };
        vertexBuff = static_cast<OpenGLVertexBuffer*>(VertexBuffer::create(vertices, sizeof(vertices)));

        BufferLayout layout = {
            {ShaderDataType::Float3, "a_pos"},
            {ShaderDataType::Float4, "a_color"}
        };
        vertexBuff->setLayout(layout);

        unsigned int el_index = 0;
        for (const auto& el : layout) {
            glEnableVertexAttribArray(el_index);
            glVertexAttribPointer(el_index, el.getCount(), getGlType(el._type), el._normalized ? GL_TRUE : GL_FALSE, layout.getStride(), (const void*)el._offset);
            el_index++;
        }

        unsigned int indices[36] = {
            0, 1, 2, 2, 1, 3, // -Z face
            4, 5, 6, 6, 5, 7, // +Z face
            0, 2, 4, 4, 2, 6, // -X face
            1, 3, 5, 5, 3, 7, // +X face
            2, 3, 6, 6, 3, 7, // +Y face
            0, 4, 1, 1, 4, 5  // -Y face
        };
        indexBuff = static_cast<OpenGLIndexBuffer*>(IndexBuffer::create(indices, 36));
         
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        const std::string vertexShader = R"(
        #version 330 core

        layout(location = 0) in vec3 a_pos;
        layout(location = 1) in vec4 a_color;
        
        out vec4 v_color;
        
        void main(){
            float theta = 15.f;
            float angleX = theta;
            float angleY = theta;
            float angleZ = theta;

            mat4 rotX = mat4(
                1.0, 0.0, 0.0, 0.0,
                0.0, cos(angleX), -sin(angleX), 0.0,
                0.0, sin(angleX), cos(angleX), 0.0,
                0.0, 0.0, 0.0, 1.0
            );

            mat4 rotY = mat4(
                cos(angleY), 0.0, sin(angleY), 0.0,
                0.0, 1.0, 0.0, 0.0,
                -sin(angleY), 0.0, cos(angleY), 0.0,
                0.0, 0.0, 0.0, 1.0
            );

            mat4 rotZ = mat4(
                cos(angleZ), -sin(angleZ), 0.0, 0.0,
                sin(angleZ), cos(angleZ), 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0
            );

            mat4 rotation = rotZ * rotY * rotX;           
            vec4 rotated_pos = rotation * vec4(a_pos, 1.0);

            v_color = a_color;
            gl_Position = rotated_pos;
        }
        )";

        const std::string fragmentShader = R"(
        #version 330 core

        layout(location = 0) out vec4 o_color;

        in vec4 v_color;

        void main(){
            o_color = v_color;
        }
        )";

        shader = new OpenGLShader(vertexShader, fragmentShader);

        vertexBuff->unbind();
        indexBuff->unbind();
    }

    Application::~Application(){
        delete shader;
        delete vertexBuff;
        delete indexBuff;
    }

    void Application::run(){
        while(m_running){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.2f, 0.2f, 0.2f, 1.f);

            vertexBuff->bind();
            indexBuff->bind();
            shader->bind();
            glBindVertexArray(vertexArr);
            glDrawElements(GL_TRIANGLES, indexBuff->getCount(), GL_UNSIGNED_INT, nullptr);
            
            for(Layer* layer : m_layerStack){
                layer->onUpdate();
            }

            m_imguiLayer->begin();
            for(Layer* layer : m_layerStack){
                layer->onImGuiDraw();
            }
            m_imguiLayer->end();
            vertexBuff->unbind();
            indexBuff->unbind();
            shader->unbind();
            
            m_window->onUpdate();
        }
    }

    void Application::onEvent(Event& e){
        EventDispatcher dispatcher(e);

        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(onWindowClose));

        for(auto it = m_layerStack.end(); it != m_layerStack.begin(); ){
            (*--it)->onEvent(e);
            if(e.isHandled()){
                break;
            }
        }
    }

    void Application::pushLayer(Layer* layer) { m_layerStack.pushLayer(layer); layer->onAttach(); }
    void Application::pushOverlay(Layer* overlay) { m_layerStack.pushOverlay(overlay); overlay->onAttach(); }

    bool Application::onWindowClose(WindowCloseEvent& e){
        m_running = false;
        return true;
    }

}