#ifndef DE_OPENGL_SHADER_H
#define DE_OPENGL_SHADER_H

#include <string>

#include "Renderer/Shader.h"

namespace DarknessEngine{
    class OpenGLShader : public Shader{
    public:
        OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);
        ~OpenGLShader();

        void bind() const override;
        void unbind() const override;
    private:
        uint32_t m_id;

        bool checkShaderCompileStatus(unsigned int& shader);
        bool checkProgramLinking();
    };
}

#endif