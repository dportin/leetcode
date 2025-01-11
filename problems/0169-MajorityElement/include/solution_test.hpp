#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class MajorityElement : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionSorting, SolutionHashTable, SolutionBoyerMoore>;

TYPED_TEST_SUITE(MajorityElement, Implementations);

TYPED_TEST(MajorityElement, Example1) {

    // Example 1:

    // Input: nums = [3,2,3]
    // Output: 3

    std::vector<int> input = {3,2,3};
    int result = this->solution.majorityElement(input);
    ASSERT_EQ(result, 3);

}

TYPED_TEST(MajorityElement, Example2) {

    // Example 2:

    // Input: nums = [2,2,1,1,1,2,2]
    // Output: 2

    std::vector<int> input = {2,2,1,1,1,2,2};
    int result = this->solution.majorityElement(input);
    ASSERT_EQ(result, 2);

}

TYPED_TEST(MajorityElement, Example3) {

    std::vector<int> input = {1,1,2,2,2,1,1};
    int result = this->solution.majorityElement(input);
    ASSERT_EQ(result, 1);

}

TYPED_TEST(MajorityElement, Example4) {

    std::vector<int> input = {6,5,5};
    int result = this->solution.majorityElement(input);
    ASSERT_EQ(result, 5);

}

#endif // SOLUTION_TEST_HPP