#include "client.h"
#include "serverbase.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockServer : public Server
{
public:
    // 模拟没有参数的成员函数
    MOCK_METHOD0(TestFunc1, bool());
    MOCK_METHOD0(TestFunc2, std::vector<int>());

    // 模拟const成员函数
    MOCK_CONST_METHOD1(TestFunc3, int(int));

    // 模拟带有参数的成员函数，宏的最后一个数字表示参数个数
    MOCK_METHOD2(TestFunc4, int(int, int));

    // 模拟带有 noexcept 和 const 的成员函数，宏的最后一个参数可以是const override noexcept的任意几个
    MOCK_METHOD(int, TestFunc5, (int), (const, noexcept));
};

class MyCompositeClassTest : public ::testing::Test
{
protected:
    ~MyCompositeClassTest() override = default;

    MyCompositeClassTest()
    {
        // 设置 MyCompositeClass 的成员变量 m_server 默认的预期值
        ON_CALL(m_server, TestFunc1()).WillByDefault(::testing::Return(true));
        ON_CALL(m_server, TestFunc2()).WillByDefault(::testing::Return(std::vector<int> { 1, 2, 3 }));
        ON_CALL(m_server, TestFunc3(3)).WillByDefault(::testing::Return(9));
        ON_CALL(m_server, TestFunc4(2, 3)).WillByDefault(::testing::Return(5));
        ON_CALL(m_server, TestFunc5(1)).WillByDefault(::testing::Return(6));
    }

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

protected:
    MockServer m_server {};
};

TEST_F(MyCompositeClassTest, TestFunc1)
{
    MyCompositeClass composite(m_server);
    EXPECT_EQ(composite.TestFunc1(), true);
}

TEST_F(MyCompositeClassTest, TestFunc2)
{
    MyCompositeClass composite(m_server);
    EXPECT_EQ(composite.TestFunc2(), (std::vector<int> { 1, 2, 3 })); // 注意要把 std::vector<int> 使用 () 括起来，不然宏展开会出错
}

TEST_F(MyCompositeClassTest, TestFunc3)
{
    MyCompositeClass composite(m_server);
    EXPECT_EQ(composite.TestFunc3(3), 9);
}

TEST_F(MyCompositeClassTest, TestFunc4)
{
    MyCompositeClass composite(m_server);
    EXPECT_EQ(composite.TestFunc4(2, 3), 5);
}

TEST_F(MyCompositeClassTest, TestFunc5)
{
    MyCompositeClass composite(m_server);
    // 当输入参数为'1'时，设置的默认返回为6，但是参数为'11'时，并没有设置默认返回，int类型的期望是0（不等于6），所以这个测试用例失败
    EXPECT_EQ(composite.TestFunc5(11), 6);
}
