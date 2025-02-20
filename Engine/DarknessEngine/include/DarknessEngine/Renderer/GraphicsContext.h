#ifndef DE_GRAPHICS_CONTEXT_H
#define DE_GRAPHICS_CONTEXT_H

namespace DarknessEngine{
    class GraphicsContext{
    public:
        virtual void init() = 0;
        virtual void swapBuffers() = 0;
    };
}

#endif