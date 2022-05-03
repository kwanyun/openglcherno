#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID)); // 버퍼생성하고 해당주소 반환
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //우린 이 버퍼를 쓸꺼다
    GLCall(glBufferData(GL_ARRAY_BUFFER,size, data, GL_STATIC_DRAW)); //버퍼 사이즈, vertex를 버퍼에 insert
}
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //우린 이 버퍼를 쓸꺼다
}
void VertexBuffer::UnBind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); //0으로 바인드
}