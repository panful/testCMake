
#pragma once

#include "global.h"

class MyMath_EXPORT MyMath
{
public:
    constexpr MyMath(int v0, int v1) noexcept
        : m_var0(v0), m_var1(v1)
    {
    }

public:
    constexpr int Add() const noexcept;
    constexpr int Sub() const noexcept;

private:
    int m_var0;
    int m_var1;
};