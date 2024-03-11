#include "client.h"
#include "myserver.h"
#include <iostream>

int main()
{
    MyServer server;
    MyCompositeClass composite(server);
    composite.TestFunc1();
    composite.TestFunc2();
    composite.TestFunc3(2);
    composite.TestFunc4(3, 4);
    composite.TestFunc5(5);

    return 0;
}
