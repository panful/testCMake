#include "client.h"
#include "myserver.h"
#include <algorithm>
#include <iostream>

//--------------------------------------------------------------------------
int MyFunc()
{
    return 666;
}

//--------------------------------------------------------------------------
void MySimpleClass::DoSomeThing()
{
    m_data++;
}

int MySimpleClass::GetData() const noexcept
{
    return m_data;
}

//--------------------------------------------------------------------------
MyCompositeClass::MyCompositeClass(Server& s) : m_server(s)
{
}

bool MyCompositeClass::TestFunc1() const
{
    return m_server.TestFunc1();
}

std::vector<int> MyCompositeClass::TestFunc2() const
{
    return m_server.TestFunc2();
}

int MyCompositeClass::TestFunc3(int n) const
{
    return m_server.TestFunc3(n);
}

int MyCompositeClass::TestFunc4(int m, int n)
{
    return m_server.TestFunc4(m, n);
}

int MyCompositeClass::TestFunc5(int n) const noexcept
{
    return m_server.TestFunc5(n);
}
