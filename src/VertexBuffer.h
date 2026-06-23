#pragma once
#include <memory>


class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;


private:
	unsigned int m_uRendererId;
};

typedef std::unique_ptr<VertexBuffer> VertexBufferPtr;