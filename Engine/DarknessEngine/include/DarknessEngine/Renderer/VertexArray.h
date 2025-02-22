#ifndef DE_VERTEX_ARRAY_H
#define DE_VERTEX_ARRAY_H

#include <memory>
#include <vector>

#include "Renderer/Buffer.h"
#include "Renderer/BufferLayout.h"

namespace DarknessEngine {
	class VertexArray {
	public:
		virtual ~VertexArray() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vbo) = 0;
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& ebo) = 0;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const = 0;

		static VertexArray* create();
	};
}

#endif
