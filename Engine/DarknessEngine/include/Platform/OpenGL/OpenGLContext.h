#ifndef DE_OPENGL_CONTEXT_H
#define DE_OPENGL_CONTEXT_H

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace DarknessEngine{
    class OpenGLContext : public GraphicsContext{
    public:
        OpenGLContext(GLFWwindow* glfwWindow);

        void init() override;
        void swapBuffers() override;

    private:
        GLFWwindow* m_Window;
    };
}

#endif
