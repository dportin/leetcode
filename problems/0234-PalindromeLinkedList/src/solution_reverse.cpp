#include "solution_base.hpp"

bool SolutionReverse::isPalindrome(LinkedList<int>& list) {

    if (list.head == nullptr || list.head->next == nullptr) {
        return true;
    }

    LinkedList<int>::Node* slow = list.head;
    LinkedList<int>::Node* fast = list.head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkedList<int>::Node* next = nullptr;
    LinkedList<int>::Node* prev = nullptr;
    
    while (slow != nullptr) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    list.last = prev;
    LinkedList<int>::Node* head = list.head;

    while (prev != nullptr) {
        if (head->value != prev->value) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }

    return true;

}
