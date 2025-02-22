#include "Renderer/Buffer.h"

#ifdef DE_RENDERER_OPENGL
    #include "Platform/OpenGL/OpenGLBuffer.h"
#endif

namespace DarknessEngine{

    VertexBuffer* VertexBuffer::create(float* vertices, size_t size){
#ifdef DE_RENDERER_OPENGL
        return new OpenGLVertexBuffer(vertices, size);
#endif
        return nullptr;
    }

    IndexBuffer* IndexBuffer::create(unsigned int* indices, uint32_t count){
#ifdef DE_RENDERER_OPENGL
        return new OpenGLIndexBuffer(indices, count);
#endif
        return nullptr;
    }

}