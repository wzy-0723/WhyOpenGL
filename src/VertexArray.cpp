#include <glad/glad.h>
#include "VertexArray.h"
#include "GLUtil.h"


VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_uRendererId));
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_uRendererId);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();

	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i,				// 属性槽位编号，对应顶点着色器中 layout(location = N) in vec3 aPos; 的 N
			element.count,							// 单个属性有几个分量
			element.type,							//  
			element.normalized,						// 
			layout.GetStride(),						// 相邻两个顶点，同一属性起始位置相差多少字节。
			(const void*)offset));					// 缓冲内字节偏移，即读取的起点

		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_uRendererId));

}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));

}