#include <demo.h>
#include <iostream>

int main()
{
    std::cout << "---call demo library---\n";
    
    std::cout << "2 + 3 = " << add(2,3) << std::endl;
    std::cout << "5 - 3 = " << sub(5,3) << std::endl;
    
    return 0;
}