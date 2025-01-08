#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

#include <vector>
#include <algorithm>

template <typename T>
class SolutionTest : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionOnePass, SolutionTwoPass>;

TYPED_TEST_SUITE(SolutionTest, Implementations);

TYPED_TEST(SolutionTest, Example1) {

    // Example 1:

    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    // Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    std::vector<int> numbers = {2, 7, 11, 15};
    std::vector<int> expected = {0, 1};

    std::vector<int> result = this->solution.twoSum(numbers, 9);
    std::sort(result.begin(), result.end());
    ASSERT_EQ(result, expected);

}

TYPED_TEST(SolutionTest, Example2) {

    // Example 2:

    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]

    std::vector<int> numbers = {3, 2, 4};
    std::vector<int> expected = {1, 2};

    std::vector<int> result = this->solution.twoSum(numbers, 6);
    std::sort(result.begin(), result.end());
    ASSERT_EQ(result, expected);

}

TYPED_TEST(SolutionTest, Example3) {

    // Example 3:

    // Input: nums = [3,3], target = 6
    // Output: [0,1]

    std::vector<int> numbers = {3, 3};
    std::vector<int> expected = {0, 1};

    std::vector<int> result = this->solution.twoSum(numbers, 6);
    std::sort(result.begin(), result.end());
    ASSERT_EQ(result, expected);

}

#endif // SOLUTION_TEST_HPP