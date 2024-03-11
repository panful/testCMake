#pragma once

#include "serverbase.h"

//--------------------------------------------------------------------------
int MyFunc();

//--------------------------------------------------------------------------
class MySimpleClass
{
public:
    void DoSomeThing();

    int GetData() const noexcept;

private:
    int m_data { 0 };
};

//--------------------------------------------------------------------------
class MyCompositeClass
{
public:
    MyCompositeClass(Server&);

    bool TestFunc1() const;
    std::vector<int> TestFunc2() const;
    int TestFunc3(int) const;
    int TestFunc4(int, int);
    int TestFunc5(int) const noexcept;

private:
    Server& m_server;
};
