#include "pch.h"

#include "Core/Application.h"

#include <glad/glad.h>

//DBG Triangle
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
unsigned int vertexArr;
DarknessEngine::OpenGLShader* shader;
DarknessEngine::OpenGLVertexBuffer* vertexBuff;
DarknessEngine::OpenGLIndexBuffer* indexBuff;

namespace DarknessEngine{

#define BIND_EVENT_FUNC(func) std::bind(&Application::func, this, std::placeholders::_1)

    Application* Application::s_inst = nullptr;

    Application::Application(){
        if(s_inst){
            std::cerr << "Application instance already exists!\n";
            return;
        }
        s_inst = this;

        m_window = std::unique_ptr<Window>(Window::create());
        m_window->setEventCallback(BIND_EVENT_FUNC(onEvent));

        m_imguiLayer = new ImGuiLayer();
        pushOverlay(m_imguiLayer);

        glGenVertexArrays(1, &vertexArr);
        glBindVertexArray(vertexArr);

        float vertices[3 * 4] = 
        {
            //x     y      z
            -0.5f,   0.5f,   0.0f,
            -0.5f,  -0.5f,   0.0f,
            0.5f,   -0.5f,   0.0f,
            0.5f,   0.5f,   0.0f
        };
        vertexBuff = static_cast<OpenGLVertexBuffer*>(VertexBuffer::create(vertices, sizeof(vertices)));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };
        indexBuff = static_cast<OpenGLIndexBuffer*>(IndexBuffer::create(indices, 6));

        const std::string vertexShader = R"(
        #version 330 core

        layout(location = 0) in vec3 a_pos;

        out vec3 v_pos;

        void main(){
            v_pos = a_pos;
            gl_Position = vec4(1.5 * a_pos, 1.0);
        }
        )";

        const std::string fragmentShader = R"(
        #version 330 core

        layout(location = 0) out vec4 o_color;

        in vec3 v_pos;

        void main(){
            vec3 color = (v_pos + 0.5);
            o_color = vec4(color, 1.0);
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