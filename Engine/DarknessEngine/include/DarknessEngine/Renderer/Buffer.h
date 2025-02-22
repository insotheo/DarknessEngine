#ifndef DE_BUFFER_H
#define DE_BUFFER_H

#include <iostream>

#include "Renderer/BufferLayout.h"

namespace DarknessEngine{
    class VertexBuffer{
    public:
        virtual ~VertexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual void setLayout(const BufferLayout& layout) = 0;
        virtual const BufferLayout& getLayout() const = 0;

        static VertexBuffer* create(float* vertices, size_t size);
    };

    class IndexBuffer{
    public:
        virtual ~IndexBuffer() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual uint32_t getCount() const = 0;

        static IndexBuffer* create(unsigned int* indices, uint32_t count);
    };
}

#endif