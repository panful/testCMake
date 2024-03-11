#pragma once

#include <vector>

class Server
{
public:
    virtual ~Server() = default;

    virtual bool TestFunc1()             = 0;
    virtual std::vector<int> TestFunc2() = 0;

    virtual int TestFunc3(int) const = 0;
    virtual int TestFunc4(int, int)  = 0;

    virtual int TestFunc5(int) const noexcept = 0;
};
