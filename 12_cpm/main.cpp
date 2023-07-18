#include <iostream>
#include <glm/glm.hpp>

int main()
{
    std::cout << "--- Test CPM ---\n";

    glm::vec3 vec3(1.f, 2.f, 3.f);
    std::cout << vec3.x << '\t' << vec3.y << '\t' << vec3.z << '\n';

    return 0;
}