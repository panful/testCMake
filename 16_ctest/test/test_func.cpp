#include "client.h"
#include <gtest/gtest.h>

// 第一个参数是测试用例名，一般一组相关的测试使用同一个用例名，比如测试同一个函数
// 第二个参数是具体的测试名称，同一组测试用例（测试用例名相同），不能有相同的测试名
// 即两个参数不能同时相同
TEST(Test_MyFunc, test_1)
{
    int result = MyFunc();  // 调用需要测试的函数
    EXPECT_EQ(result, 666); // 验证结果是否符合预期
}

TEST(Test_MyFunc, test_2)
{
    int result = MyFunc();
    EXPECT_EQ(result, 777);
}

TEST(Test_MyFunc, test_3)
{
    int result = MyFunc();
    EXPECT_EQ(result, 666);
}
