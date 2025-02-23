#ifndef DE_OPENGL_RENDERER_API_H
#define DE_OPENGL_RENDERER_API_H

#include "Renderer/RendererAPI.h"

namespace DarknessEngine {
	class OpenGLRendererAPI : public RendererAPI {
	public:
		void clear() override;
		void clearColor(const glm::vec4& color) override;
		void drawIndexed(const std::shared_ptr<VertexArray>& obj) override;
	};
}

#endif