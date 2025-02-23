#ifndef DE_RENDER_COMMAND_H
#define DE_RENDER_COMMAND_H

#include "Renderer/RendererAPI.h"

namespace DarknessEngine {
	class RenderCommand {
	public:
		inline static void clear() { s_api->clear(); }
		inline static void clearColor(const glm::vec4& color) { s_api->clearColor(color); }
		inline static void drawIndexed(const std::shared_ptr<VertexArray>& obj) { s_api->drawIndexed(obj); }

	private:
		static RendererAPI* s_api;
	};
}

#endif
