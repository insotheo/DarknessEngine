#include "Platform/Windows/WindowsInput.hpp"

#include "Platform/Windows/WindowsWindow.hpp"

#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace DarknessEngine{
    Input* Input::s_inst = new WindowsInput();

    bool WindowsInput::isKeyPressed_impl(int keycode){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNative());
        int state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::isMouseButtonPressed_impl(int button){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNative());
        int state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS || state == GLFW_PRESS;
    }

    float WindowsInput::getMouseXPos_impl(){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNative());
        double x;
        glfwGetCursorPos(window, &x, nullptr);
        return (float)x; 
    }

    float WindowsInput::getMouseYPos_impl(){
        GLFWwindow* window = static_cast<GLFWwindow*>(Application::getInstance().getWindowRef().getNative());
        double y;
        glfwGetCursorPos(window, nullptr, &y);
        return (float)y; 
    }
}