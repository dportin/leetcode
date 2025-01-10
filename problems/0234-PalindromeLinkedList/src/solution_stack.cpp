#include "solution_base.hpp"

#include <stack>

bool SolutionStack::isPalindrome(LinkedList<int>& list) {

    if (list.head == nullptr || list.head->next == nullptr) {
        return true;
    }

    std::stack<int> stack;
    LinkedList<int>::Node* slow = list.head;
    LinkedList<int>::Node* fast = list.head;

    while (fast != nullptr && fast->next != nullptr) {
        stack.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != nullptr) {
        slow = slow->next;
    }
    
    while (slow != nullptr) {
        int value = stack.top();
        stack.pop();
        if (value != slow->value) {
            return false;
        }
        slow = slow->next;
    }

    return true;

}