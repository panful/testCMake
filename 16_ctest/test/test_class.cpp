#include "client.h"
#include <gtest/gtest.h>

// 测试套件
class MySimpleClassTest : public ::testing::Test
{
protected:
    // 在测试套件中的每个测试用例之前执行
    // 可以在这里进行一些初始化工作
    void SetUp() override
    {
        m_mySimpleClass.DoSomeThing();
    }

    // 在测试套件中的每个测试用例之后执行
    // 可以在这里进行一些清理工作
    void TearDown() override
    {
    }

protected:
    MySimpleClass m_mySimpleClass {}; // 不能声明为private ，否则不能在测试用例中使用这个成员变量
};

// MySimpleClassTest 中的成员变量并不会在测试用例中共享，这是为了保持测试用例的独立性
TEST_F(MySimpleClassTest, DoSomeThingTest_1)
{
    m_mySimpleClass.DoSomeThing();
    EXPECT_EQ(m_mySimpleClass.GetData(), 2); // 通过（累加两次，SetUp一次，测试用例一次）
}

TEST_F(MySimpleClassTest, DoSomeThingTest_2)
{
    m_mySimpleClass.DoSomeThing();
    EXPECT_EQ(m_mySimpleClass.GetData(), 3); // 不通过，因为只累加了2次（SetUp一次，测试用例一次，成员变量不共享）
}
