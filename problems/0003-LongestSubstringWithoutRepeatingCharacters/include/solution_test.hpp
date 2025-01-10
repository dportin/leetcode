#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class LongestSubstringWithoutRepeatingCharacters : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionWindow, SolutionWindowIndex>;

TYPED_TEST_SUITE(LongestSubstringWithoutRepeatingCharacters, Implementations);

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, Example1) {

    // Example 1:

    // Input: s = "abcabcbb"
    // Output: 3
    // Explanation: The answer is "abc", with the length of 3.

    std::string input = "abcabcbb";
    int expected = 3;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, Example2) {

    // Example 2:

    // Input: s = "bbbbb"
    // Output: 1
    // Explanation: The answer is "b", with the length of 1.

    std::string input = "bbbbb";
    int expected = 1;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, Example3) {

    // Example 3:

    // Input: s = "pwwkew"
    // Output: 3
    // Explanation: The answer is "wke", with the length of 3.
    // Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    
    std::string input = "pwwkew";
    int expected = 3;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, Empty) {

    std::string input = "";
    int expected = 0;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, OneCharacter) {

    std::string input = "a";
    int expected = 1;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

TYPED_TEST(LongestSubstringWithoutRepeatingCharacters, Alphabet) {

    std::string input = "abcdefghijklmnopqrstuvwxyz";
    int expected = 26;

    int result = this->solution.lengthOfLongestSubstring(input);
    ASSERT_EQ(result, expected);

}

#endif // SOLUTION_TEST_HPP