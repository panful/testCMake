#include <mymath.h>
#include <iostream>

int main()
{
    std::cout << "exe call shared, shared call static\n";
    
    MyMath m(3, 1);
    std::cout << "test add: 3 + 1 = " << m.Add() << '\n';
    std::cout << "test add: 3 - 1 = " << m.Sub() << '\n';

    return 0;
}