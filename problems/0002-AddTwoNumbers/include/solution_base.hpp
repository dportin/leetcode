#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include "linked_list.hpp"

class SolutionBase {

public:
    
    virtual LinkedList<int> addTwoNumbers(const LinkedList<int>& left, const LinkedList<int>& right) = 0;

};

class SolutionDefault : public SolutionBase {

public:

    LinkedList<int> addTwoNumbers(const LinkedList<int>& left, const LinkedList<int>& right) override;

};

#endif // SOLUTION_BASE_HPP
