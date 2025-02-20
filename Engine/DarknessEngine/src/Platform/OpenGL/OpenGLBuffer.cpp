#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

namespace DarknessEngine{

    //VERTEX
    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, size_t size){
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer(){
        glDeleteBuffers(1, &m_id);
    }

    void OpenGLVertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void OpenGLVertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    //INDEX
    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indices, uint32_t count) 
        : m_count(count) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &m_id);
    }

    void OpenGLIndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void OpenGLIndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}