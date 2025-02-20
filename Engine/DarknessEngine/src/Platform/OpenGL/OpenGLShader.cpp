#include "Platform/OpenGL/OpenGLShader.h"

#include <glad/glad.h>

namespace DarknessEngine{
    OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource){
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char* src = vertexSource.c_str();
        glShaderSource(vertexShader, 1, &src, 0);
        glCompileShader(vertexShader);
        if(!checkShaderCompileStatus(vertexShader)){
            glDeleteShader(vertexShader);
            return;
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        src = fragmentSource.c_str();
        glShaderSource(fragmentShader, 1, &src, 0);
        glCompileShader(fragmentShader);
        if(!checkShaderCompileStatus(fragmentShader)){
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            return;
        }

        m_id = glCreateProgram();
        glAttachShader(m_id, vertexShader);
        glAttachShader(m_id, fragmentShader);

        glLinkProgram(m_id);
        if(!checkProgramLinking()){
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            return;
        }

        glDetachShader(m_id, vertexShader);
        glDetachShader(m_id, fragmentShader);
    }

    OpenGLShader::~OpenGLShader(){
        glDeleteProgram(m_id);
    }

    void OpenGLShader::bind() const{
        glUseProgram(m_id);
    }

    void OpenGLShader::unbind() const{
        glUseProgram(0);
    }

    bool OpenGLShader::checkShaderCompileStatus(unsigned int& shader){
        int status = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if(status == GL_FALSE){
            return false;
        }
        return true;
    }

    bool OpenGLShader::checkProgramLinking(){
        int status = 0;
        glGetProgramiv(m_id, GL_LINK_STATUS, &status);
        if(status == GL_FALSE){
            glDeleteProgram(m_id);
            return false;
        }
        return true;
    }
}