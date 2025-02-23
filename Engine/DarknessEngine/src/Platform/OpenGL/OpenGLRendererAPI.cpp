#include "Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace DarknessEngine {
	void OpenGLRendererAPI::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::clearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::drawIndexed(const std::shared_ptr<VertexArray>& obj)
	{
		glDrawElements(GL_TRIANGLES, obj.get()->getIndexBuffer().get()->getCount(), GL_UNSIGNED_INT, nullptr);
	}
}