#pragma once

#include "serverbase.h"

class MyServer : public Server
{
public:
    ~MyServer() override = default;

    bool TestFunc1() override;
    std::vector<int> TestFunc2() override;
    int TestFunc3(int) const override;
    int TestFunc4(int, int) override;
    int TestFunc5(int) const noexcept override;
};
