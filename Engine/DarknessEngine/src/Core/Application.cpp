#include "pch.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>
#include <cmath>

namespace DarknessEngine{

    Application::Application(){
        m_Window = std::unique_ptr<Window>(Window::create());

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
            m_Window->onUpdate();
        }
    }

}