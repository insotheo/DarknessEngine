#ifndef DE_SHADER_H
#define DE_SHADER_H

namespace DarknessEngine{
    class Shader{
    public:
        virtual ~Shader() {}

        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    };
}

#endif