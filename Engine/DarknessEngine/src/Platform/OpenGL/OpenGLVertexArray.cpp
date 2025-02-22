#include "Platform/OpenGL/OpenGLVertexArray.h"

#include "Core/Core.h"
#include "Renderer/BufferLayout.h"

#include <glad/glad.h>

namespace DarknessEngine {
	static GLenum getGlType(const DarknessEngine::ShaderDataType& t) {
		switch (t)
		{
		case DarknessEngine::ShaderDataType::Float:
		case DarknessEngine::ShaderDataType::Float2:
		case DarknessEngine::ShaderDataType::Float3:
		case DarknessEngine::ShaderDataType::Float4:
		case DarknessEngine::ShaderDataType::Mat3:
		case DarknessEngine::ShaderDataType::Mat4:
			return GL_FLOAT;

		case DarknessEngine::ShaderDataType::Int:
		case DarknessEngine::ShaderDataType::Int2:
		case DarknessEngine::ShaderDataType::Int3:
		case DarknessEngine::ShaderDataType::Int4:
			return GL_INT;


		case DarknessEngine::ShaderDataType::Boolean:
			return GL_BOOL;
		}

		DE_ASSERT(false, "Unknown Shader data type");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_id);
	}

	OpenGLVertexArray::~OpenGLVertexArray() {
		glDeleteVertexArrays(1, &m_id);
	}

	void OpenGLVertexArray::bind() const {
		glBindVertexArray(m_id);
	}

	void OpenGLVertexArray::unbind() const {
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vbo) {
		glBindVertexArray(m_id);
		vbo->bind();
		unsigned int el_index = 0;
		const auto& layout = vbo->getLayout();
		for (const auto& el : layout) {
			glEnableVertexAttribArray(el_index);
			glVertexAttribPointer(el_index, el.getCount(), getGlType(el._type), el._normalized ? GL_TRUE : GL_FALSE, layout.getStride(), (const void*)el._offset);
			el_index++;
		}
		m_vertexBuffers.push_back(vbo);
		glBindVertexArray(0);
		vbo->unbind();
	}

	void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& ebo) {
		glBindVertexArray(m_id);
		ebo->bind();
		m_indexBuffer = ebo;
		glBindVertexArray(0);
		ebo->unbind();
	}
}