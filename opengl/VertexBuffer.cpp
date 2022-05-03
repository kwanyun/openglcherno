#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID)); // ���ۻ����ϰ� �ش��ּ� ��ȯ
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //�츰 �� ���۸� ������
    GLCall(glBufferData(GL_ARRAY_BUFFER,size, data, GL_STATIC_DRAW)); //���� ������, vertex�� ���ۿ� insert
}
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //�츰 �� ���۸� ������
}
void VertexBuffer::UnBind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); //0���� ���ε�
}