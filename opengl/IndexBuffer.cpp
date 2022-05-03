#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count)
    :m_Count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_RendererID)); // ���ۻ����ϰ� �ش��ּ� ��ȯ
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID)); //�츰 �� ���۸� ������
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int), data, GL_STATIC_DRAW)); //���� ������, vertex�� ���ۿ� insert
}
IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //�츰 �� ���۸� ������
}
void IndexBuffer::UnBind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); //0���� ���ε�
}