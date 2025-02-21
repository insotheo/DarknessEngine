#ifndef DE_BUFFER_LAYOUT_H
#define DE_BUFFER_LAYOUT_H

#include <string>
#include <vector>

namespace DarknessEngine {

	enum class ShaderDataType {
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Boolean
	};
	size_t getSizeOfType(const ShaderDataType& type);

	struct BufferElement {
		std::string _name;
		ShaderDataType _type;
		size_t _size;
		size_t _offset;
		bool _normalized;

		BufferElement() {}

		BufferElement(const ShaderDataType type, const std::string& name, bool normalized = false)
			: _type(type), _name(name), _size(getSizeOfType(type)), _offset(0), _normalized(normalized)
		{
		}

		size_t getCount() const;
	};

	class BufferLayout {
	public:
		BufferLayout() {}

		BufferLayout(const std::initializer_list<BufferElement>& e)
			: m_elements(e)
		{
			calcElOffsetsAndStride();
		}

		inline const std::vector<BufferElement>& getElements() const { return m_elements; }
		inline const size_t& getStride() const { return m_stride; }

		std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_elements.end(); }

		std::vector<BufferElement>::const_iterator begin() const { return m_elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_elements.end(); }
	private:
		std::vector<BufferElement> m_elements;
		size_t m_stride = 0;

	private:
		void calcElOffsetsAndStride(); //El stands for Element
	};
}

#endif