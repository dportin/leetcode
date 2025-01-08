#include "solution_base.hpp"
#include "warnings.hpp"

#include <unordered_map>

std::vector<int> SolutionTwoPass::twoSum(std::vector<int>& numbers, int target) {

    std::unordered_map<int, int> indices;

    for (size_t i = 0; i < numbers.size(); ++i) {
        indices[numbers[i]] = i;
    }

    DISABLE_WARNING_PUSH
    DISABLE_WARNING_SIGN_COMPARE

    for (int i = 0; i < numbers.size(); ++i) {
        int subtarget = target - numbers[i];
        if (indices.count(subtarget) && indices[subtarget] != i) {
            return {i, indices[subtarget]};
        }
    }

    DISABLE_WARNING_POP

    return {};

}