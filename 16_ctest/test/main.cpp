
#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}

/*
ASSERT_* 版本在断言失败时会产生一个致命错误，并终止当前函数的执行。
EXPECT_* 版本在断言失败时会产生一个非致命错误，当前函数会继续执行，这允许测试多个条件。

基础断言 ASSERT_TRUE ASSERT_FALSE
二进制比较 ASSERT_EQ ASSERT_NE ASSERT_LT ASSERT_LE ASSERT_GT ASSERT_GE
字符串比较 ASSERT_STREQ ASSERT_STRNE ASSERT_STRCASEEQ ASSERT_STRCASENE
浮点数比较 ASSERT_FLOAT_EQ ASSERT_DOUBLE_EQ ASSERT_NEAR（自定义精度）

成功失败断言 FAIL ADD_FAILURE
类型对比断言 ::testing::StaticAssertTypeEq<T,T>()
异常断言 ASSERT_THROW ASSERT_ANY_THROW ASSERT_NO_THROW
谓词断言 ASSERT_PRED1 ASSERT_PRED2
子过程中使用断言 SCOPED_TRACE

TEST_F 避免拷贝
值参数化 TEST_P  testing::TestWithParam Generator
类型参数化 TYPE_TEST TYPED_TEST_P
死亡测试 ASSERT_DEATH
testing::Test  SetUp()  TearDown()
testing::Test  SetUpTestCase() TearDownTestCase()
testing::Environmen

特殊测试
测试筛选 --gtest_list_tests --gtest_filter=<匹配模式>
禁止测试 DISABLED_
重复测试 --gtest_repeat=<N>

输出文件
xml:  --gtest_out="xml:<file_path>" 环境变量 set GTEST_OUTPUT=xml:<file_path>
json: --gtest_out="json:<file_path>" 环境变量 set GTEST_OUTPUT=json:<file_path>
自定义记录 testing::Test::RecordProperty
*/
