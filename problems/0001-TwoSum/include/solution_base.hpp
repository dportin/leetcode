#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual std::vector<int> twoSum(std::vector<int>& nums, int target) = 0;

};

class SolutionOnePass : public SolutionBase {

public:

    virtual std::vector<int> twoSum(std::vector<int>& nums, int target) override;

};

class SolutionTwoPass : public SolutionBase {

public:

    virtual std::vector<int> twoSum(std::vector<int>& nums, int target) override;

};

#endif // SOLUTION_BASE_HPP
