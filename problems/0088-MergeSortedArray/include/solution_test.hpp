#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class MergeSortedArray : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(MergeSortedArray, Implementations);

TYPED_TEST(MergeSortedArray, Example1) {

    // Example 1:

    // Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    // Output: [1,2,2,3,5,6]
    // Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    // The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

    std::vector<int> left = {1,2,3,0,0,0};
    std::vector<int> right = {2,5,6};
    std::vector<int> expected = {1,2,2,3,5,6};

    this->solution.merge(left, 3, right, 3);
    ASSERT_EQ(left, expected);

}

TYPED_TEST(MergeSortedArray, Example2) {

    // Example 2:

    // Input: nums1 = [1], m = 1, nums2 = [], n = 0
    // Output: [1]
    // Explanation: The arrays we are merging are [1] and [].
    // The result of the merge is [1].

    std::vector<int> left = {1};
    std::vector<int> right = {};
    std::vector<int> expected = {1};

    this->solution.merge(left, 1, right, 0);
    ASSERT_EQ(left, expected);

}

TYPED_TEST(MergeSortedArray, Example3) {

    // Example 3:

    // Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    // Output: [1]
    // Explanation: The arrays we are merging are [] and [1].
    // The result of the merge is [1].
    // Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

    std::vector<int> left = {0};
    std::vector<int> right = {1};
    std::vector<int> expected = {1};

    this->solution.merge(left, 0, right, 1);
    ASSERT_EQ(left, expected);

}

#endif // SOLUTION_TEST_HPP