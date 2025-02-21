#include "Renderer/BufferLayout.h"

#include "Core/Core.h"

namespace DarknessEngine {

	size_t getSizeOfType(const ShaderDataType& type) {
		switch (type)
		{
		case ShaderDataType::Float:		return 4;
		case ShaderDataType::Float2:	return 4 * 2;
		case ShaderDataType::Float3:	return 4 * 3;
		case ShaderDataType::Float4:	return 4 * 4;
		case ShaderDataType::Int:		return 4;
		case ShaderDataType::Int2:		return 4 * 2;
		case ShaderDataType::Int3:		return 4 * 3;
		case ShaderDataType::Int4:		return 4 * 4;
		case ShaderDataType::Mat3:		return 4 * 3 * 3;
		case ShaderDataType::Mat4:		return 4 * 4 * 4;
		case ShaderDataType::Boolean:	return 1;
		}

		DE_ASSERT(false, "Unknown Shader data type!");
		return 0;
	}

	size_t BufferElement::getCount() const{
		switch (_type)
		{
		case ShaderDataType::Float:		return 1;
		case ShaderDataType::Float2:	return 2;
		case ShaderDataType::Float3:	return 3;
		case ShaderDataType::Float4:	return 4;
		case ShaderDataType::Int:		return 1;
		case ShaderDataType::Int2:		return 2;
		case ShaderDataType::Int3:		return 3;
		case ShaderDataType::Int4:		return 4;
		case ShaderDataType::Mat3:		return 3 * 3;
		case ShaderDataType::Mat4:		return 4 * 4;
		case ShaderDataType::Boolean:	return 1;
		}

		DE_ASSERT(false, "Unknown Shader data type!");
		return 0;
	}

	void BufferLayout::calcElOffsetsAndStride() {
		m_stride = 0;
		size_t off = 0; //offset
		for (auto& e : m_elements) {
			e._offset = off;
			off += e._size;
			m_stride += e._size;
		}
	}
}