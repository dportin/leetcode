#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include <vector>

class SolutionBase {

public:
    
    virtual void merge(std::vector<int>& left, int n, const std::vector<int>& right, int m) = 0;

};

class SolutionDefault : public SolutionBase {

public:

    void merge(std::vector<int>& left, int n, const std::vector<int>& right, int m) override;

};

#endif // SOLUTION_BASE_HPP
