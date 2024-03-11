#include "myserver.h"

bool MyServer::TestFunc1()
{
    return true;
}

std::vector<int> MyServer::TestFunc2()
{
    return { 1, 2, 3, 4, 5 };
}

int MyServer::TestFunc3(int n) const
{
    return n * n;
}

int MyServer::TestFunc4(int m, int n)
{
    return m + n;
}

int MyServer::TestFunc5(int n) const noexcept
{
    return n + 5;
}
