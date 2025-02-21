#include "Platform/OpenGL/OpenGLContext.h"

// #include "pch.h"
#include "Core/Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace DarknessEngine{
    OpenGLContext::OpenGLContext(GLFWwindow* glfwWindow) : m_window(glfwWindow)
    {
        if(!glfwWindow){
            Log::error("OpenGL context error: no window exists!", "OpenGL context");
            return;
        }
    }

    void OpenGLContext::init(){
        glfwMakeContextCurrent(m_window);

        //Glad init
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(status != GLFW_TRUE){
            //TODO: Make Glad error callback
            return;
        }

        // Log::info("OpenGL info:", "OpenGL");
        // Log::info("\tvendor: " +  (std::string)((char*)glGetString(GL_VENDOR)), "OpenGL");
        // Log::info("\trenderer: " + (std::string)((char*)glGetString(GL_RENDERER)), "OpenGL");
        // Log::info("\tversion: " + (std::string)((char*)glGetString(GL_VERSION)), "OpenGL");
    }

    void OpenGLContext::swapBuffers(){
        glfwSwapBuffers(m_window);
    }
}