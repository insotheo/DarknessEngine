#include "Renderer/RenderCommand.h"

#ifdef DE_RENDERER_OPENGL
#include "Platform/OpenGL/OpenGLRendererAPI.h"
#endif

namespace DarknessEngine {
#ifdef DE_RENDERER_OPENGL
	RendererAPI* RenderCommand::s_api = new OpenGLRendererAPI();
#endif
}