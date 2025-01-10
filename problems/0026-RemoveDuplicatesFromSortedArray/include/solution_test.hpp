#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class RemoveDuplicatesFromSortedArray : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(RemoveDuplicatesFromSortedArray, Implementations);

TYPED_TEST(RemoveDuplicatesFromSortedArray, Example1) {

    // Example 1:

    // Input: nums = [1,1,2]
    // Output: 2, nums = [1,2,_]
    // Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> input = {1,1,2};
    std::vector<int> expected = {1,2};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray, Example2) {

    // Example 2:

    // Input: nums = [0,0,1,1,1,2,2,3,3,4]
    // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    // Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> input = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> expected = {0,1,2,3,4};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray, AllSame) {

    std::vector<int> input = {1,1,1,1,1,1,1};
    std::vector<int> expected = {1};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray, Empty) {

    std::vector<int> input = {};
    std::vector<int> expected = {};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

#endif // SOLUTION_TEST_HPP