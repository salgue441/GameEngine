/**
 * @file math.test.h
 * @author Carlos Salguero
 * @brief Test class for math classs
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MATH_TEST_H
#define MATH_TEST_H

// Google Test Library
#include <gtest/gtest.h>

// Project headers
#include "src/utils/math/math.h"

using namespace Math;

/**
 * @brief
 * Construct a new TEST object
 * @param TestMath class
 * @param TestAdd method
 */
TEST(TestMath, TestAdd)
{
    EXPECT_EQ(add<int>(2, 3), 5);
    EXPECT_EQ(add<float>(2.5, 3.5), 6.0);
    EXPECT_EQ(add<double>(2.5, 3.5), 6.0);
    EXPECT_EQ(add<long>(2, 3), 5);
    EXPECT_EQ(add<long long>(2, 3), 5);
    EXPECT_EQ(add<unsigned int>(2, 3), 5);
    EXPECT_EQ(add<unsigned long>(2, 3), 5);
    EXPECT_EQ(add<unsigned long long>(2, 3), 5);
}

/**
 * @brief
 * Construct a new TEST object
 * @param TestMath class
 * @param TestSub method
 */
TEST(TestMath, TestSub)
{
    EXPECT_EQ(subtract<int>(2, 3), -1);
    EXPECT_EQ(subtract<float>(2.5, 3.5), -1.0);
    EXPECT_EQ(subtract<double>(2.5, 3.5), -1.0);
    EXPECT_EQ(subtract<long>(2, 3), -1);
    EXPECT_EQ(subtract<long long>(2, 3), -1);
    EXPECT_EQ(subtract<unsigned int>(2, 3), -1);
    EXPECT_EQ(subtract<unsigned long>(2, 3), -1);
    EXPECT_EQ(subtract<unsigned long long>(2, 3), -1);
}

/**
 * @brief
 * Construct a new TEST object
 * @param TestMath class
 * @param TestMul method
 */
TEST(TestMath, TestMul)
{
    EXPECT_EQ(multiply<int>(2, 3), 6);
    EXPECT_EQ(multiply<float>(2.5, 3.5), 8.75);
    EXPECT_EQ(multiply<double>(2.5, 3.5), 8.75);
    EXPECT_EQ(multiply<long>(2, 3), 6);
    EXPECT_EQ(multiply<long long>(2, 3), 6);
    EXPECT_EQ(multiply<unsigned int>(2, 3), 6);
    EXPECT_EQ(multiply<unsigned long>(2, 3), 6);
    EXPECT_EQ(multiply<unsigned long long>(2, 3), 6);
}

/**
 * @brief
 * Construct a new TEST object
 * @param TestMath class
 * @param TestDiv method
 */
TEST(TestMath, TestDiv)
{
    EXPECT_EQ(divide<int>(2, 3), 0);
    EXPECT_EQ(divide<float>(2.5, 3.5), 0.7142857142857143);
    EXPECT_EQ(divide<double>(2.5, 3.5), 0.7142857142857143);
    EXPECT_EQ(divide<long>(2, 3), 0);
    EXPECT_EQ(divide<long long>(2, 3), 0);
    EXPECT_EQ(divide<unsigned int>(2, 3), 0);
    EXPECT_EQ(divide<unsigned long>(2, 3), 0);
    EXPECT_EQ(divide<unsigned long long>(2, 3), 0);
}

#endif //! MATH_TEST_H