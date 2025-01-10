#include "solution_base.hpp"

#include <vector>

void SolutionDefault::merge(std::vector<int>& left, int n, const std::vector<int>& right, int m) {

    int i = n - 1;
    int j = m - 1;
    int p = n + m - 1;

    while (j >= 0) {

        if (i >= 0 && left[i] > right[j]) {
            left[p--] = left[i--];
        }
        else {
            left[p--] = right[j--]; 
        }

    }

}