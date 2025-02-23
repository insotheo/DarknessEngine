#include "Renderer/Renderer.h"

#include "Renderer/RenderCommand.h"

namespace DarknessEngine {
	void Renderer::begin() {

	}

	void Renderer::end() {

	}

	void Renderer::submit(const std::shared_ptr<VertexArray>& obj) {
		obj->bind();
		RenderCommand::drawIndexed(obj);
		obj->unbind();
	}
}