#include "solution_base.hpp"

int SolutionDefault::removeDuplicates(std::vector<int>& nums) {

    if (nums.empty()) {
        return 0;
    }

    std::size_t length = 1;
    
    for (std::size_t i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] != nums[i]) {
            nums[length++] = nums[i]; 
        }
    }

    nums.resize(length);
    return static_cast<int>(length);

}
