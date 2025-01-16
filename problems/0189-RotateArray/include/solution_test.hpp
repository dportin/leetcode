#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>

template <typename T>
class RotateArray : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionReverse>;

TYPED_TEST_SUITE(RotateArray, Implementations);

TYPED_TEST(RotateArray, Example1) {

    // Example 1:

    // Input: nums = [1,2,3,4,5,6,7], k = 3
    // Output: [5,6,7,1,2,3,4]
    // Explanation:
    // rotate 1 steps to the right: [7,1,2,3,4,5,6]
    // rotate 2 steps to the right: [6,7,1,2,3,4,5]
    // rotate 3 steps to the right: [5,6,7,1,2,3,4]

    std::vector<int> input = {1,2,3,4,5,6,7};
    std::vector<int> expected1 = {7,1,2,3,4,5,6};
    std::vector<int> expected2 = {6,7,1,2,3,4,5};
    std::vector<int> expected3 = {5,6,7,1,2,3,4};
    std::vector<int> expected4 = {4,5,6,7,1,2,3};
    std::vector<int> expected5 = {3,4,5,6,7,1,2};
    std::vector<int> expected6 = {2,3,4,5,6,7,1};
    std::vector<int> expected7 = {1,2,3,4,5,6,7};

    std::vector<int> input1 = input;
    this->solution.rotate(input1, 1);
    ASSERT_EQ(input1, expected1);

    std::vector<int> input2 = input;
    this->solution.rotate(input2, 2);
    ASSERT_EQ(input2, expected2);

    std::vector<int> input3 = input;
    this->solution.rotate(input3, 3);
    ASSERT_EQ(input3, expected3);

    std::vector<int> input4 = input;
    this->solution.rotate(input4, 4);
    ASSERT_EQ(input4, expected4);

    std::vector<int> input5 = input;
    this->solution.rotate(input5, 5);
    ASSERT_EQ(input5, expected5);

    std::vector<int> input6 = input;
    this->solution.rotate(input6, 6);
    ASSERT_EQ(input6, expected6);

    std::vector<int> input7 = input;
    this->solution.rotate(input7, 7);
    ASSERT_EQ(input7, expected7);

}

TYPED_TEST(RotateArray, Example2) {

    // Example 2:

    // Input: nums = [-1,-100,3,99], k = 2
    // Output: [3,99,-1,-100]
    // Explanation: 
    // rotate 1 steps to the right: [99,-1,-100,3]
    // rotate 2 steps to the right: [3,99,-1,-100]

    std::vector<int> input = {-1,-100,3,99};
    std::vector<int> expected1 = {99,-1,-100,3};
    std::vector<int> expected2 = {3,99,-1,-100};
    std::vector<int> expected3 = {-100,3,99,-1};
    std::vector<int> expected4 = {-1,-100,3,99};

    std::vector<int> input1 = input;
    this->solution.rotate(input1, 1);
    ASSERT_EQ(input1, expected1);

    std::vector<int> input2 = input;
    this->solution.rotate(input2, 2);
    ASSERT_EQ(input2, expected2);

    std::vector<int> input3 = input;
    this->solution.rotate(input3, 3);
    ASSERT_EQ(input3, expected3);

    std::vector<int> input4 = input;
    this->solution.rotate(input4, 4);
    ASSERT_EQ(input4, expected4);

}

TYPED_TEST(RotateArray, AlgorithmStress) {

    std::vector<int> base(100);
    std::iota(base.begin(), base.end(), 0);
    
    for (size_t i = 0; i < base.size(); ++i) {
        for (size_t n = 0; n < 4; ++n) {
            
            std::vector<int> input = base;
            std::vector<int> expected = base;
            std::rotate(expected.begin(), expected.begin() + expected.size() - i, expected.end());
            this->solution.rotate(input, i + n * input.size());
            ASSERT_EQ(input, expected);

        }
    }

}

#endif // SOLUTION_TEST_HPP