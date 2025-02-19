#include "Platform/Windows/WindowsWindow.hpp"

#include "Core/Log.h"

#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"

#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>

namespace DarknessEngine
{
    static bool s_GLFWInit = false;

    static void glfwErrCallback(int errCode, const char* description){
        std::stringstream er;
        er << "GLFW ERROR[" << errCode << "]: " << description;
        LOG_CORE_ERROR(er.str());
    }

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
            glfwSetErrorCallback(glfwErrCallback);
            if(success != GLFW_TRUE){
                return;
            }
            s_GLFWInit = true;
        }
        
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
        m_Ctx = new OpenGLContext(m_Window);
        m_Ctx->init();

        glfwSetWindowUserPointer(m_Window, &m_Data);
        setVSync(true);

        //callback setters
        #pragma region Callbacks
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){ //CLOSE
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){ //SIZE
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = (unsigned int)width;
            data.Height = (unsigned int)height;

            WindowResizeEvent event((unsigned int)width, (unsigned int)height);
            data.EventCallback(event);
        });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused){ //GOT AND LOST FOCUS
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            if(focused == GLFW_TRUE){
                WindowGotFocusEvent event;
                data.EventCallback(event);
            }
            else if(focused == GLFW_FALSE){
                WindowLostFocusEvent event;
                data.EventCallback(event);
            }
        });

        glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int x, int y){ //MOVED
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowMovedEvent event((float)x, (float)y);
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){ //KEYS
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                KeyPressedEvent pressed(key, 1);
                data.EventCallback(pressed);
            }
            else if(action == GLFW_RELEASE){
                KeyReleasedEvent release(key);
                data.EventCallback(release);
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int c){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            KeyTypedEvent event(c);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){ //MOUSE PRESSED AND RELEASED
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                MouseButtonPressedEvent pressed(button);
                data.EventCallback(pressed);
            }
            else if(action == GLFW_RELEASE){
                MouseButtonReleasedEvent released(button);
                data.EventCallback(released);
            }
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y){ //MOUSE POSITION
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)x, (float)y);
            data.EventCallback(event);
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOff, double yOff){ //SCROLL
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOff, (float)yOff);
            data.EventCallback(event);
        });
        #pragma endregion
    }

    void WindowsWindow::onUpdate(){
        glfwPollEvents();
        m_Ctx->swapBuffers();
    }


    void WindowsWindow::shutdown(){
        glfwDestroyWindow(m_Window);
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
