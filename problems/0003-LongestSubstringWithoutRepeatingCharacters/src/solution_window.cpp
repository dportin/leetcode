#include "solution_base.hpp"

#include <unordered_set>
#include <algorithm>

int SolutionWindow::lengthOfLongestSubstring(const std::string& str) {

    size_t length = 0;
    std::unordered_set<char> visited;
    
    size_t lo = 0;
    size_t hi = 0;

    while (hi < str.size()) {

        while (visited.contains(str[hi])) {
            visited.erase(str[lo++]);
        }

        visited.insert(str[hi++]);
        length = std::max(length, hi - lo);
        
    }

    return static_cast<int>(length);

}