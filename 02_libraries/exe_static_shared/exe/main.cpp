#include <myMath.h>
#include <iostream>

int main()
{
    std::cout << "exe call static library, static call dynamic\n";

    MyMath math;
    std::cout << "test add: 4 + 2 = " << math.add(4, 2) << '\n';
    std::cout << "test sub: 5 - 2 = " << math.sub(5, 2) << '\n';

    return 0;
}