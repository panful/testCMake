#include "plus.h"
#include "sub.h"
#include <iostream>

int main()
{
    std::cout << "test package\n";

    {
        Plus plus {};
        plus.SetNumber1(2);
        plus.SetNumber2(2);
        std::cout << "plus(2, 2) = " << plus.GetResult() << std::endl;
    }

    {
        Sub sub {};
        sub.SetNumber1(5);
        sub.SetNumber2(1);
        std::cout << "sub(5, 1) = " << sub.GetResult() << std::endl;
    }

    return 0;
}
