#ifndef DE_BUFFER_H
#define DE_BUFFER_H

#include <iostream>

namespace DarknessEngine{
    class VertexBuffer{
    public:
        virtual ~VertexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        static VertexBuffer* create(float* vertices, size_t size);
    };

    class IndexBuffer{
    public:
        virtual ~IndexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        static IndexBuffer* create(unsigned int* indices, uint32_t count);
    };
}

#endif