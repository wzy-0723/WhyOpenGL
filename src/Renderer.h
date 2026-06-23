#pragma once
#include <glad/glad.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "shader.h"
#include "GLUtil.h"

//void GLClearError();
//bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

typedef std::unique_ptr<Renderer> RendererPtr;