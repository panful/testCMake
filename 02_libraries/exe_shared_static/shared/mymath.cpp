#include "mymath.h"
#include "sub.h"
#include "plus.h"

MyMath::MyMath(int a, int b)
    : m_number0(a), m_number1(b)
{
}

int MyMath::Add() const
{
    return plus(m_number0, m_number1);
}

int MyMath::Sub() const
{
    return sub(m_number0, m_number1);
}