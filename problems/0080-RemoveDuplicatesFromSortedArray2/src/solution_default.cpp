#include "solution_base.hpp"

int SolutionDefault::removeDuplicates(std::vector<int>& nums) {

    if (nums.size() < 3) {
        return nums.size();
    }

    std::size_t length = 1;

    // nums[p] == nums[i]
    //     nums[p] == nums[p - 1]
    //         ++i
    //     nums[p] != nums[p - 1]
    //         nums[++p] = nums[i]
    //         ++i
    // nums[p] != nums[i]
    //     nums[++p] = nums[i]
    //     ++i

    // nums[p] != nums[i] || nums[p] != nums[p - 1] => nums[++p] = nums[i]
    // nums[p] == nums[i] && nums[p] == nums[p - 1] => continue

    for (std::size_t i = 2; i < nums.size(); ++i) {
        if (nums[length] != nums[i] || nums[length] != nums[length - 1]) {
            nums[++length] = nums[i];
        }
    }

    nums.resize(++length);
    return static_cast<int>(length);

}
