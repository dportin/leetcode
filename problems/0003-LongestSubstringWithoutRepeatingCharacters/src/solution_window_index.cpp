#include "solution_base.hpp"

#include <unordered_map>
#include <algorithm>

int SolutionWindowIndex::lengthOfLongestSubstring(const std::string& str) {

    size_t length = 0;
    std::unordered_map<char, size_t> indices;
    std::unordered_map<char, size_t>::const_iterator index;
    
    size_t lo = 0;
    size_t hi = 0;

    while (hi < str.size()) {

        index = indices.find(str[hi]);
        if (index != indices.end()) {
            lo = std::max(lo, index->second + 1);
        }

        indices[str[hi++]] = hi;
        length = std::max(length, hi - lo);
        
    }

    return static_cast<int>(length);

}
