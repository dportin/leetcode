#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual void rotate(std::vector<int>& nums, int k) = 0;

};

class SolutionReverse : public SolutionBase {

public:

    void rotate(std::vector<int>& nums, int k) override;

};

#endif // SOLUTION_BASE_HPP
