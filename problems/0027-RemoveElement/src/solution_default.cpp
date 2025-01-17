#include "solution_base.hpp"

int SolutionDefault::removeElement(std::vector<int>& nums, int val) {

    std::size_t length = 0;
    
    for (std::size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[length++] = nums[i];
        }
    }

    nums.resize(length);
    return static_cast<int>(length);

}
