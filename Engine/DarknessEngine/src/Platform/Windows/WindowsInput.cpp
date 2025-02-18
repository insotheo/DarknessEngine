#include "Platform/Windows/WindowsInput.hpp"

#include "Core/Application.h"
#include "Platform/Windows/WindowsWindow.hpp"

#include <GLFW/glfw3.h>

namespace DarknessEngine{
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::isKeyPressedIMPL(int keycode){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNativeWindow());
        int state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::isMouseButtonPressedIMPL(int button){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNativeWindow());
        int state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS || state == GLFW_PRESS;
    }

    float WindowsInput::getMouseXPosIMPL(){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNativeWindow());
        double x;
        glfwGetCursorPos(window, &x, nullptr);
        return (float)x; 
    }

    float WindowsInput::getMouseYPosIMPL(){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNativeWindow());
        double y;
        glfwGetCursorPos(window, nullptr, &y);
        return (float)y; 
    }
}