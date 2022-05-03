#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count)
    :m_Count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_RendererID)); // 버퍼생성하고 해당주소 반환
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID)); //우린 이 버퍼를 쓸꺼다
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int), data, GL_STATIC_DRAW)); //버퍼 사이즈, vertex를 버퍼에 insert
}
IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //우린 이 버퍼를 쓸꺼다
}
void IndexBuffer::UnBind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); //0으로 바인드
}