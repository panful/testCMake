
#include "gtest/gtest.h"
#include <iostream>

// 测试 gtest 是否导入成功
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    std::cout << "RUN ALL TESTS: " << ret << '\n';
    return ret;
}
