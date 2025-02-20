#ifndef DE_OPENGL_BUFFER_H
#define DE_OPENGL_BUFFER_H

#include "Renderer/Buffer.h"

namespace DarknessEngine{
    class OpenGLVertexBuffer : public VertexBuffer{
    public:
        OpenGLVertexBuffer(float* vertices, size_t size);
        ~OpenGLVertexBuffer();

        void bind() const override;
        void unbind() const override;
    private:
        uint32_t m_id;
    };

    class OpenGLIndexBuffer : public IndexBuffer{
    public:
        OpenGLIndexBuffer(unsigned int* indices, uint32_t count);
        ~OpenGLIndexBuffer();

        void bind() const override;
        void unbind() const override;

        inline uint32_t getCount() const { return m_count; }
    private:
        uint32_t m_id;
        uint32_t m_count;
    };

}

#endif