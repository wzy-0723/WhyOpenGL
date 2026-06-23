#include <glad/glad.h>
#include "VertexBuffer.h"
#include "GLUtil.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &m_uRendererId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_uRendererId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_uRendererId));

}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_uRendererId));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

