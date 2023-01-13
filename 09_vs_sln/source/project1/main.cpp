#include <iostream>

int func()
{
    return 1;
}

int main()
{
    int a = 0;
    int b = 1;
    int c = 2;

    auto ret = func();

    std::cout << "Hello Visual Studio\n";

    a = 2;
    b = 3;
    c = 4;

    return 0;
}