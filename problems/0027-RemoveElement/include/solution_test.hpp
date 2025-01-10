#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class RemoveElement : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(RemoveElement, Implementations);

TYPED_TEST(RemoveElement, Example1) {

    // Example 1:

    // Input: nums = [3,2,2,3], val = 3
    // Output: 2, nums = [2,2,_,_]
    // Explanation: Your function should return k = 2, with the first two elements of nums being 2.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> numbers = {3,2,2,3};
    std::vector<int> expected = {2,2};

    int length = this->solution.removeElement(numbers, 3);
    std::sort(numbers.begin(), numbers.end());
    std::sort(expected.begin(), expected.end());
    ASSERT_EQ(numbers, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveElement, Example2) {

    // Example 2:

    // Input: nums = [0,1,2,2,3,0,4,2], val = 2
    // Output: 5, nums = [0,1,4,0,3,_,_,_]
    // Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
    // Note that the five elements can be returned in any order.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> numbers = {0,1,2,2,3,0,4,2};
    std::vector<int> expected = {0,1,4,0,3};

    int length = this->solution.removeElement(numbers, 2);
    std::sort(numbers.begin(), numbers.end());
    std::sort(expected.begin(), expected.end());
    ASSERT_EQ(numbers, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveElement, Empty) {

    std::vector<int> numbers = {};
    std::vector<int> expected = {};

    int length = this->solution.removeElement(numbers, 2);
    std::sort(numbers.begin(), numbers.end());
    std::sort(expected.begin(), expected.end());
    ASSERT_EQ(numbers, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveElement, RemoveAll) {

    std::vector<int> numbers = {2,2,2,2,2};
    std::vector<int> expected = {};

    int length = this->solution.removeElement(numbers, 2);
    std::sort(numbers.begin(), numbers.end());
    std::sort(expected.begin(), expected.end());
    ASSERT_EQ(numbers, expected);
    ASSERT_EQ(length, expected.size());

}

#endif // SOLUTION_TEST_HPP