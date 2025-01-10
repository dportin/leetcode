#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class AddTwoNumbers : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(AddTwoNumbers, Implementations);

TYPED_TEST(AddTwoNumbers, Example1) {

    // Example 1:

    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.

    LinkedList<int> left = LinkedList<int>::from_vector({2,4,3});
    LinkedList<int> right = LinkedList<int>::from_vector({5,6,4});
    LinkedList<int> expected = LinkedList<int>::from_vector({7,0,8});
    
    LinkedList<int> result = this->solution.addTwoNumbers(left, right);
    ASSERT_TRUE(result == expected);

}

TYPED_TEST(AddTwoNumbers, Example2) {

    // Example 2:

    // Input: l1 = [0], l2 = [0]
    // Output: [0]

    LinkedList<int> left = LinkedList<int>::from_vector({0});
    LinkedList<int> right = LinkedList<int>::from_vector({0});
    LinkedList<int> expected = LinkedList<int>::from_vector({0});
    
    LinkedList<int> result = this->solution.addTwoNumbers(left, right);
    ASSERT_TRUE(result == expected);

}

TYPED_TEST(AddTwoNumbers, Example3) {

    // Example 3:

    // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]

    LinkedList<int> left = LinkedList<int>::from_vector({9,9,9,9,9,9,9});
    LinkedList<int> right = LinkedList<int>::from_vector({9,9,9,9});
    LinkedList<int> expected = LinkedList<int>::from_vector({8,9,9,9,0,0,0,1});
    
    LinkedList<int> result = this->solution.addTwoNumbers(left, right);
    ASSERT_TRUE(result == expected);

}

#endif // SOLUTION_TEST_HPP