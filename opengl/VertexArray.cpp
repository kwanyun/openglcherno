#include "VertexArray.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        Bind();
        vb.Bind();
        const auto& element = elements[i];
        glEnableVertexAttribArray(i); //시작, 0번 버퍼

        //insert한 버퍼를 해석하는 방법으로 몇차원인지, index는, 크기, 시작위치등
        //glVertexAttribPointer에서 vao와 buffer를 연결
        glVertexAttribPointer(i, element.count, element.type, element.normalized , layout.GetStride(), (const void *)offset);
        offset += element.count*VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}
