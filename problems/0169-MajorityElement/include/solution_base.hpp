#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual int majorityElement(const std::vector<int>& nums) = 0;

};

class SolutionSorting : public SolutionBase {

public:

    int majorityElement(const std::vector<int>& nums) override;

};

class SolutionHashTable : public SolutionBase {

public:

    int majorityElement(const std::vector<int>& nums) override;

};

class SolutionBoyerMoore : public SolutionBase {

public:

    int majorityElement(const std::vector<int>& nums) override;

};

#endif // SOLUTION_BASE_HPP
