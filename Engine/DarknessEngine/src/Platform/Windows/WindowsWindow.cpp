#include "Platform/Windows/WindowsWindow.hpp"

#include "Core/Core.h"
#include "Core/Log.h"

#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/ApplicationEvent.hpp"

#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>

namespace DarknessEngine
{
    static bool s_GLFWInit = false;

    static void glfwErrCallback(int errCode, const char* description){
        std::stringstream er;
        er << "GLFW ERROR[" << errCode << "]: " << description;
        LOG_CORE_ERROR(er.str());
        DE_ASSERT(false, er.str());
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
        m_data._title = props._title;
        m_data._width = props._width;
        m_data._height = props._height;

        
        LOG_CORE_TRACE("Creating window...");
        
        if(!s_GLFWInit){
            int success = glfwInit();
            glfwSetErrorCallback(glfwErrCallback);
            if(success != GLFW_TRUE){
                return;
            }
            s_GLFWInit = true;
        }
        
        m_window = glfwCreateWindow((int)props._width, (int)props._height, props._title.c_str(), nullptr, nullptr);
        m_ctx = new OpenGLContext(m_window);
        m_ctx->init();

        glfwSetWindowUserPointer(m_window, &m_data);
        setVSync(true);

        //callback setters
        #pragma region callbacks
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){ //CLOSE
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data._eventCallback(event);
        });

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height){ //SIZE
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data._width = (unsigned int)width;
            data._height = (unsigned int)height;

            WindowResizeEvent event((unsigned int)width, (unsigned int)height);
            data._eventCallback(event);
        });

        glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused){ //GOT AND LOST FOCUS
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            if(focused == GLFW_TRUE){
                WindowGotFocusEvent event;
                data._eventCallback(event);
            }
            else if(focused == GLFW_FALSE){
                WindowLostFocusEvent event;
                data._eventCallback(event);
            }
        });

        glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int x, int y){ //MOVED
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            WindowMovedEvent event((float)x, (float)y);
            data._eventCallback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){ //KEYS
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                KeyPressedEvent pressed(key, 1);
                data._eventCallback(pressed);
            }
            else if(action == GLFW_RELEASE){
                KeyReleasedEvent release(key);
                data._eventCallback(release);
            }
        });

        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int c){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            KeyTypedEvent event(c);
            data._eventCallback(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods){ //MOUSE PRESSED AND RELEASED
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                MouseButtonPressedEvent pressed(button);
                data._eventCallback(pressed);
            }
            else if(action == GLFW_RELEASE){
                MouseButtonReleasedEvent released(button);
                data._eventCallback(released);
            }
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y){ //MOUSE POSITION
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)x, (float)y);
            data._eventCallback(event);
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOff, double yOff){ //SCROLL
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOff, (float)yOff);
            data._eventCallback(event);
        });
        #pragma endregion
    }

    void WindowsWindow::onUpdate(){
        glfwPollEvents();
        m_ctx->swapBuffers();
    }


    void WindowsWindow::shutdown(){
        glfwDestroyWindow(m_window);
    }

    void WindowsWindow::setVSync(bool state){
        if(state){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }

        m_data.VSync = state;
    }

    bool WindowsWindow::isVSync() const{ return m_data.VSync; }

}
