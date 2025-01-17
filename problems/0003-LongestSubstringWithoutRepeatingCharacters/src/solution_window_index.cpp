#include "solution_base.hpp"

#include <unordered_map>
#include <algorithm>

int SolutionWindowIndex::lengthOfLongestSubstring(const std::string& str) {

    std::size_t length = 0;
    std::unordered_map<char, std::size_t> indices;
    std::unordered_map<char, std::size_t>::const_iterator index;
    
    std::size_t lo = 0;
    std::size_t hi = 0;

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
