#include "sub.h"

void Sub::SetNumber1(int num)
{
    m_number1 = num;
}

void Sub::SetNumber2(int num)
{
    m_number2 = num;
}

int Sub::GetResult() const noexcept
{
    return m_number1 - m_number2;
}
