#include "pch.h"

#include "Core/Application.h"

#include <glad/glad.h>
#include <cmath>

namespace DarknessEngine{

#define BIND_EVENT_FUNC(func) std::bind(&Application::func, this, std::placeholders::_1)

    Application* Application::s_Instance = nullptr;

    Application::Application(){
        if(s_Instance){
            std::cerr << "Application instance already exists!\n";
            return;
        }
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::create());
        m_Window->setEventCallback(BIND_EVENT_FUNC(onEvent));

        m_ImGuiLayer = new ImGuiLayer();
        pushOverlay(m_ImGuiLayer);
    }

    Application::~Application(){
    }

    void Application::run(){
        float time = 0;
        while(m_Running){
            glClear(GL_COLOR_BUFFER_BIT);

            time += 0.01f;
            float r = (sin(time) + 1.0f) / 2.0f;
            float g = (sin(time + 2.0f) + 1.0f) / 2.0f;
            float b = (sin(time + 4.0f) + 1.0f) / 2.0f;
            glClearColor(r, g, b, 1);

            for(Layer* layer : m_LayerStack){
                layer->onUpdate();
            }

            m_ImGuiLayer->begin();
            for(Layer* layer : m_LayerStack){
                layer->onImGuiDraw();
            }
            m_ImGuiLayer->end();

            m_Window->onUpdate();
        }
    }

    void Application::onEvent(Event& e){
        EventDispatcher dispatcher(e);

        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(onWindowClose));

        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ){
            (*--it)->onEvent(e);
            if(e.isHandled()){
                break;
            }
        }
    }

    void Application::pushLayer(Layer* layer) { m_LayerStack.pushLayer(layer); layer->onAttach(); }
    void Application::pushOverlay(Layer* overlay) { m_LayerStack.pushOverlay(overlay); overlay->onAttach(); }

    bool Application::onWindowClose(WindowCloseEvent& e){
        m_Running = false;
        return true;
    }

}