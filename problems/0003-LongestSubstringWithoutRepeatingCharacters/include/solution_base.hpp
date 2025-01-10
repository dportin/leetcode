#ifndef SOLUTION_BASE_HPP
#define SOLUTION_BASE_HPP

#include "linked_list.hpp"

class SolutionBase {

public:
    
    virtual int lengthOfLongestSubstring(const std::string& str) = 0;

};

class SolutionWindow : public SolutionBase {

public:

    int lengthOfLongestSubstring(const std::string& str) override;

};

class SolutionWindowIndex : public SolutionBase {

public:

    int lengthOfLongestSubstring(const std::string& str) override;

};

#endif // SOLUTION_BASE_HPP
