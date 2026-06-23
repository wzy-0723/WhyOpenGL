#pragma once
#include <glad/glad.h>
#include <vector>
#include "assert.h"
#include "GLUtil.h"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:				return 4;
		case GL_UNSIGNED_INT:		return 4;
		case GL_UNSIGNED_BYTE:		return 1;
		}

		ASSERT(false);
		return 0;
	}
};


class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_uStride;
public:
	VertexBufferLayout();
	~VertexBufferLayout();

	template<typename T>
	void Push(unsigned int count)
	{
		assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		//m_elements.push_back(VertexBufferElement(GL_FLOAT, count, GL_FALSE)); C++20
		m_elements.push_back(VertexBufferElement{ GL_FLOAT, count, GL_FALSE });
		m_uStride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		m_elements.push_back(VertexBufferElement{ GL_UNSIGNED_INT, count, GL_FALSE });
		m_uStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_elements.push_back(VertexBufferElement{ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_uStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement> GetElements() const
	{
		return m_elements;
	}

	inline unsigned int GetStride() const { return m_uStride; };
};