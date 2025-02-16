#include "Platform/Windows/WindowsWindow.hpp"

#include "Core/Log.h"

namespace DarknessEngine
{
    static bool s_GLFWInit = false;

    Window* Window::create(const WindowProps& props){
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props){
        init(props);
    }

    WindowsWindow::~WindowsWindow(){
        shutdown();
    }

    void WindowsWindow::init(const WindowProps& props){
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        LOG_CORE_TRACE("Creating window...");

        if(!s_GLFWInit){
            int success = glfwInit();
            if(success != GLFW_TRUE){
                return;
            }
            s_GLFWInit = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        setVSync(true);
    }

    void WindowsWindow::shutdown(){
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::onUpdate(){
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::setVSync(bool state){
        if(state){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }

        m_Data.VSync = state;
    }

    bool WindowsWindow::isVSync() const{
        return m_Data.VSync;
    }

}
