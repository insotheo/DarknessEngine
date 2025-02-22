#include "pch.h"

#include "Core/Core.h"
#include "Core/Application.h"

#include <glad/glad.h>

//DBG figures
#include <memory>
#include "Renderer/BufferLayout.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
DarknessEngine::OpenGLShader* shader;
DarknessEngine::OpenGLVertexArray* vertexArray;

DarknessEngine::OpenGLShader* shader2;
DarknessEngine::OpenGLVertexArray* vertexArray2;

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

        vertexArray = static_cast<OpenGLVertexArray*>(VertexArray::create());
        vertexArray->unbind();
        {

            float vertices[3 * 7] = {
                // x          y           z  
                0.0f,       0.5f,        0.0f,  
                0.433f,     0.25f,       0.0f,  
                0.433f,     -0.25f,      0.0f, 
                0.0f,       -0.5f,       0.0f,   
                -0.433f,    -0.25f,      0.0f,
                -0.433f,    0.25f,       0.0f, 
            };
            std::shared_ptr<OpenGLVertexBuffer> vertexBuff(static_cast<OpenGLVertexBuffer*>(VertexBuffer::create(vertices, sizeof(vertices))));

            BufferLayout layout = {
                {ShaderDataType::Float3, "a_pos"},
            };
            vertexBuff->setLayout(layout);
            vertexBuff->unbind();
            vertexArray->addVertexBuffer(vertexBuff);

            unsigned int indices[15] = {
                0, 1, 5,
                0, 5, 4,
                0, 4, 3,
                0, 3, 2,
                0, 2, 1
            };
            std::shared_ptr<OpenGLIndexBuffer> indexBuff(static_cast<OpenGLIndexBuffer*>(IndexBuffer::create(indices, sizeof(indices) / sizeof(unsigned int))));
            indexBuff->unbind();
            vertexArray->setIndexBuffer(indexBuff);

            const std::string vertexShader = R"(
            #version 330 core

            layout(location = 0) in vec3 a_pos;
        
            out vec4 v_color;
        
            void main(){
                v_color = vec4(a_pos * 1.f + 0.5f, 1.f);
                gl_Position = vec4(a_pos, 1.f);
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
            vertexArray->unbind();
        }

        vertexArray2 = static_cast<OpenGLVertexArray*>(VertexArray::create());
        vertexArray2->unbind();
        {
            float t = 0.75f;
            float vertices2[4 * 2] = {
                // x        y    
                -t,     -t,
                -t,     t,
                t,      t,
                t,      -t,
            };
            std::shared_ptr<OpenGLVertexBuffer> vertexBuff2(static_cast<OpenGLVertexBuffer*>(VertexBuffer::create(vertices2, sizeof(vertices2))));

            BufferLayout layout = {
                {ShaderDataType::Float2, "a_pos"},
            };
            vertexBuff2->setLayout(layout);
            vertexBuff2->unbind();
            vertexArray2->addVertexBuffer(vertexBuff2);

            unsigned int indices2[6] = {
                0, 1, 2,
                0, 2, 3,
            };
            std::shared_ptr<OpenGLIndexBuffer> indexBuff2(static_cast<OpenGLIndexBuffer*>(IndexBuffer::create(indices2, sizeof(indices2) / sizeof(unsigned int))));
            indexBuff2->unbind();
            vertexArray2->setIndexBuffer(indexBuff2);

            const std::string vertexShader2 = R"(
            #version 330 core

            layout(location = 0) in vec2 a_pos;
        
            void main(){
                gl_Position = vec4(a_pos, 0.0f, 1.f);
            }
            )";

            const std::string fragmentShader2 = R"(
            #version 330 core

            layout(location = 0) out vec4 o_color;

            void main(){
                o_color = vec4(0.07f, 0.38f, 0.33f, 1.f);
            }
            )";

            shader2 = new OpenGLShader(vertexShader2, fragmentShader2);

            vertexBuff2->unbind();
            indexBuff2->unbind();
            vertexArray2->unbind();
        }
    }

    Application::~Application(){
        delete shader;
        delete vertexArray;
        delete shader2;
        delete vertexArray2;
    }

    void Application::run(){
        while(m_running){
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.2f, 0.2f, 0.2f, 1.f);

            shader2->bind();
            vertexArray2->bind();
            glDrawElements(GL_TRIANGLES, vertexArray2->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

            shader->bind();
            vertexArray->bind();
            glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
            
            for(Layer* layer : m_layerStack){
                layer->onUpdate();
            }

            m_imguiLayer->begin();
            for(Layer* layer : m_layerStack){
                layer->onImGuiDraw();
            }
            m_imguiLayer->end();
            vertexArray->unbind();
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