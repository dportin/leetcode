#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual int removeElement(std::vector<int>& nums, int val) = 0;

};

class SolutionDefault : public SolutionBase {

public:

    int removeElement(std::vector<int>& nums, int val) override;

};

#endif // SOLUTION_BASE_HPP
