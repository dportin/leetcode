#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

class SolutionBase {

public:
    
    virtual void solution(void) = 0;

};

class SolutionDefault : public SolutionBase {

public:

    void solution(void) override;

};

#endif // SOLUTION_BASE_HPP
