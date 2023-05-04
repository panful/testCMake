#include "mymath.h"
#include <iostream>

int main()
{
    MyMath m(3, 1);
    std::cout << m.Add() << '\n';
    std::cout << m.Sub() << '\n';
}