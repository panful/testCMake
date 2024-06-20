#include "plus.h"

void Plus::SetNumber1(int num)
{
    m_number1 = num;
}

void Plus::SetNumber2(int num)
{
    m_number2 = num;
}

int Plus::GetResult() const noexcept
{
    return m_number1 + m_number2;
}
