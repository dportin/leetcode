#include "solution_base.hpp"

#include <algorithm>

int SolutionSorting::majorityElement(const std::vector<int>& nums) {

    std::vector<int> copy(nums.begin(), nums.end());
    std::sort(copy.begin(), copy.end());
    return copy[copy.size() / 2];

}
