#include "solution_base.hpp"
#include "warnings.hpp"

LinkedList<int> Solution::addTwoNumbers(const LinkedList<int>& left, const LinkedList<int>& right) {
    
    LinkedList<int> result;
    LinkedList<int>::Node* lnode = left.head;
    LinkedList<int>::Node* rnode = right.head;

    int carry = 0;

    while (lnode != nullptr || rnode != nullptr || carry > 0) {
        
        if (lnode != nullptr) {
            carry += lnode->value;
            lnode = lnode->next;
        }

        if (rnode != nullptr) {
            carry += rnode->value;
            rnode = rnode->next;
        }

        result.insert_back(carry % 10);
        carry = carry / 10;
        
    }

    return result;

}
