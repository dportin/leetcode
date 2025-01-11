#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class RemoveDuplicatesFromSortedArray2 : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(RemoveDuplicatesFromSortedArray2, Implementations);

TYPED_TEST(RemoveDuplicatesFromSortedArray2, Example1) {

    // Example 1:

    // Input: nums = [1,1,1,2,2,3]
    // Output: 5, nums = [1,1,2,2,3,_]
    // Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> input = {1,1,1,2,2,3};
    std::vector<int> expected = {1,1,2,2,3};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, Example2) {

    // Example 2:

    // Input: nums = [0,0,1,1,1,1,2,3,3]
    // Output: 7, nums = [0,0,1,1,2,3,3,_,_]
    // Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
    // It does not matter what you leave beyond the returned k (hence they are underscores).

    std::vector<int> input = {0,0,1,1,1,1,2,3,3};
    std::vector<int> expected = {0,0,1,1,2,3,3};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, AllSame) {

    std::vector<int> input = {1,1,1,1,1,1,1};
    std::vector<int> expected = {1,1};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, DoubleSame) {

    std::vector<int> input = {1,1};
    std::vector<int> expected = {1,1};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, DoubleNotSame) {

    std::vector<int> input = {1,1};
    std::vector<int> expected = {1,1};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, Single) {

    std::vector<int> input = {1};
    std::vector<int> expected = {1};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

TYPED_TEST(RemoveDuplicatesFromSortedArray2, Empty) {

    std::vector<int> input = {};
    std::vector<int> expected = {};

    int length = this->solution.removeDuplicates(input);
    ASSERT_EQ(input, expected);
    ASSERT_EQ(length, expected.size());

}

#endif // SOLUTION_TEST_HPP
