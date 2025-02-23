#ifndef DE_RENDERER_API_H
#define DE_RENDERER_API_H

#include <memory>
#include <glm.hpp>

#include "Renderer/VertexArray.h"

namespace DarknessEngine {
	class RendererAPI {
	public:
		virtual void clear() = 0;
		virtual void clearColor(const glm::vec4& color) = 0;
		virtual void drawIndexed(const std::shared_ptr<VertexArray>& obj) = 0;
	};
}

#endif
