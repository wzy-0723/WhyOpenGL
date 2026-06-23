#include <glad/glad.h>
#include "IndexBuffer.h"
#include "GLUtil.h"


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:m_uCount(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLCall(glGenBuffers(1, &m_uRendererId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_uRendererId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_uRendererId));

}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uRendererId));

}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount() const 
{ 
	return m_uCount; 
};

