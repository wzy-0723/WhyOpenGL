#pragma once
#include <memory>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();


	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;

private:
	unsigned int m_uRendererId;
};

typedef std::unique_ptr<VertexArray> VertexArrayPtr;