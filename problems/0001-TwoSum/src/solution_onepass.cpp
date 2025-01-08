#include "solution_base.hpp"
#include "warnings.hpp"

#include <unordered_map>

std::vector<int> SolutionOnePass::twoSum(std::vector<int>& numbers, int target) {

    // Suppose that target == numbers[i] + numbers[j] where i < j. The hash map
    // constructed in the two-pass solution contains symmetric solutions [i, j]
    // and [j, i]. The two-pass solution always returns [i, j] and requires con-
    // structing the hash map in advance since i < j. However, the second solut-
    // ion only requires constructing the hash map up to index j.

    std::unordered_map<int, int> indices;

    DISABLE_WARNING_PUSH
    DISABLE_WARNING_SIGN_COMPARE

    for (int i = 0; i < numbers.size(); ++i) {

        int subtarget = target - numbers[i];
        if (indices.count(subtarget)) {
            return {i, indices[subtarget]};
        }
        indices[numbers[i]] = i;

    }

    DISABLE_WARNING_POP

    return {};

}