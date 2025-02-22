#ifndef DE_OPENGL_VERTEX_ARRAY_H
#define DE_OPENGL_VERTEX_ARRAY_H

#include <vector>
#include <memory>

#include "Renderer/VertexArray.h"

namespace DarknessEngine {
	class OpenGLVertexArray : public VertexArray {
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void bind() const override;
		void unbind() const override;

		void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vbo) override;
		void setIndexBuffer(const std::shared_ptr<IndexBuffer>& ebo) override;

		inline const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const { return m_vertexBuffers; }
		inline const std::shared_ptr<IndexBuffer>& getIndexBuffer() const { return m_indexBuffer; }
	private:
		uint32_t m_id;
		std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
		std::shared_ptr<IndexBuffer> m_indexBuffer;
	};
}

#endif