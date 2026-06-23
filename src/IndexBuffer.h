#pragma once
#include <memory>

class IndexBuffer
{
private:
	unsigned int m_uRendererId;
	unsigned int m_uCount;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	unsigned int GetCount() const;
};
typedef std::unique_ptr<IndexBuffer> IndexBufferPtr;
