#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include "linked_list.hpp"

class SolutionBase {

public:
    
    virtual bool isPalindrome(LinkedList<int>& list) = 0;

};

class SolutionReverse : public SolutionBase {

public:

    bool isPalindrome(LinkedList<int>& list) override;

};

class SolutionStack : public SolutionBase {

public:

    bool isPalindrome(LinkedList<int>& list) override;

};

#endif // SOLUTION_BASE_HPP
