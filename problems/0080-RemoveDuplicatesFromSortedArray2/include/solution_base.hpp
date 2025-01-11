#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual int removeDuplicates(std::vector<int>& nums) = 0;

};

class SolutionDefault : public SolutionBase {

public:

    int removeDuplicates(std::vector<int>& nums) override;

};

#endif // SOLUTION_BASE_HPP
