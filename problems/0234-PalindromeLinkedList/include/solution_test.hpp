#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class PalindromeLinkedList : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionReverse, SolutionStack>;

TYPED_TEST_SUITE(PalindromeLinkedList, Implementations);

TYPED_TEST(PalindromeLinkedList, Example1) {

    // Example 1:

    // Input: head = [1,2,2,1]
    // Output: true

    LinkedList<int> list = LinkedList<int>::from_vector({1,2,2,1});
    ASSERT_TRUE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, Example2) {

    // Example 2:

    // Input: head = [1,2]
    // Output: false

    LinkedList<int> list = LinkedList<int>::from_vector({1,2});
    ASSERT_FALSE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, Empty) {

    LinkedList<int> list = LinkedList<int>::from_vector({});
    ASSERT_TRUE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, OddTrueLength1) {

    LinkedList<int> list = LinkedList<int>::from_vector({1});
    ASSERT_TRUE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, OddTrueLength3) {

    LinkedList<int> list = LinkedList<int>::from_vector({1,3,1});
    ASSERT_TRUE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, OddTrueLength5) {

    LinkedList<int> list = LinkedList<int>::from_vector({1,3,2,3,1});
    ASSERT_TRUE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, OddFalseLength3) {

    LinkedList<int> list = LinkedList<int>::from_vector({7,3,1});
    ASSERT_FALSE(this->solution.isPalindrome(list));

}

TYPED_TEST(PalindromeLinkedList, OddFalseLength5) {

    LinkedList<int> list = LinkedList<int>::from_vector({7,3,2,3,1});
    ASSERT_FALSE(this->solution.isPalindrome(list));

}

#endif // SOLUTION_TEST_HPP