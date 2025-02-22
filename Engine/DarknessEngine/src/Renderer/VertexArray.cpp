#include "Renderer/VertexArray.h"

#ifdef DE_RENDERER_OPENGL
#include "Platform/OpenGL/OpenGLVertexArray.h"
#endif

namespace DarknessEngine {
	VertexArray* VertexArray::create() {
#ifdef DE_RENDERER_OPENGL
		return new OpenGLVertexArray();
#endif
		return nullptr;
	}
}