#include "solution_base.hpp"

#include <algorithm>

void SolutionReverse::rotate(std::vector<int>& nums, int k) {

    if (nums.size() < 2) {
        return;
    }

    std::size_t shift = k % nums.size();
    
    if (shift == 0) {
        return;
    }

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + shift);
    std::reverse(nums.begin() + shift, nums.end());

}
