#ifndef DE_RENDERER_H
#define DE_RENDERER_H

#include "Renderer/VertexArray.h"

namespace DarknessEngine {
	class Renderer {
	public:
		static void begin();
		static void submit(const std::shared_ptr<VertexArray>& obj);
		static void end();
	};
}

#endif