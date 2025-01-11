#include "solution_base.hpp"

int SolutionBoyerMoore::majorityElement(const std::vector<int>& nums) {

    // If m is the majority element then it occurs more than n / 2 times in the
    // input array. The majority element is guaranteed to exist by the problem
    // statement. The observation is that if a majority element exists then the
    // non-majority elements can be paired with the majority elements such that
    // at least one majority element is unpaired. In the following example the
    // counter tracks the number of unpaired majority elements in the array.

    // ITER STREAM          SUBSTREAM   MAJORITY    CANDIDATE   COUNTER
    // 0    []              []          -           -           0           
    // 1    [a]             [a]         a           a           1
    // 2    [a,a]           [a,a]       a           a           2
    // 3    [a,a,b]         [a,a,b]     a           a           1
    // 4    [a,a,b,b]       [a,a,b,b]   -           a           0
    // 5    [a,a,b,b,b]     [b]         b           b           1
    // 6    [a,a,b,b,b,a]   [b,a]       -           b           0
    // 7    [a,a,b,b,b,a,a] [a]         a           1           1

    int majority = 0;
    size_t count = 0;

    for (const auto& num : nums) {

        if (count == 0) {
            majority = num;
            count = 1;
        }
        else if (majority == num) {
            ++count;
        }
        else {
            --count;
        }

    }

    // If the majority were not guaranteed to exist by the problem statement
    // then we would need to check that the candidate occurred more than n / 2
    // times in the input.

    return majority;


}
