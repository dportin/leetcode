#include "solution_base.hpp"

#include <unordered_map>

int SolutionHashTable::majorityElement(const std::vector<int>& nums) {

    std::unordered_map<int, size_t> counts;

    for (const auto& num : nums) {
        auto [it, _] = counts.insert({num, 0});
        ++it->second;
    }

    int majority_num = 0;
    size_t majority_count = 0;
    
    for (const auto& [num, count] : counts) {
        if (count > majority_count) {
            majority_count = count;
            majority_num = num;
        }
    }
    
    // If the majority were not guaranteed to exist by the problem statement
    // then we would need to check that the candidate occurred more than n / 2
    // times in the input.

    return majority_num;

}
