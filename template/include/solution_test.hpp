#ifndef SOLUTION_TEST_HPP
#define SOLUTION_TEST_HPP

#include "solution_base.hpp"
#include <gtest/gtest.h>

template <typename T>
class ProblemName : public ::testing::Test {

protected:

    T solution;

};

using Implementations = ::testing::Types<SolutionDefault>;

TYPED_TEST_SUITE(ProblemName, Implementations);

TYPED_TEST(ProblemName, ExampleName) {

    ASSERT_TRUE(true);

}

#endif // SOLUTION_TEST_HPP