#include "Platform/OpenGL/OpenGLContext.h"

#include "Core/Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace DarknessEngine{
    OpenGLContext::OpenGLContext(GLFWwindow* glfwWindow) : m_Window(glfwWindow)
    {
        if(!glfwWindow){
            LOG_CORE_ERROR("OpenGL context error: no window exists!");
            return;
        }
    }

    void OpenGLContext::init(){
        glfwMakeContextCurrent(m_Window);

        //Glad init
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(status != GLFW_TRUE){
            return;
        }
    }

    void OpenGLContext::swapBuffers(){
        glfwSwapBuffers(m_Window);
    }
}