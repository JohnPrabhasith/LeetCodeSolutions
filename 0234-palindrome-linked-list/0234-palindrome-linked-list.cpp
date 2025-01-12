/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (!head || head->next == nullptr) return true;

    ListNode* fast = head;
    ListNode* slow = head;

    //Find the Mid Element
    while(fast != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    //Reverse the list from middle Element to the end of the list
    ListNode* curr = slow;
    ListNode* prev = nullptr;
    ListNode* next;

    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //Check Whether the first half of the list is equal to the second half of the list
    ListNode* FirstHalf = head;
    ListNode* SecondHalf = prev;

    while(SecondHalf != nullptr) {
        if(FirstHalf->val != SecondHalf->val) {
            return false;
        }
        FirstHalf = FirstHalf->next; 
        SecondHalf = SecondHalf->next;
    }

    return true;
    }
};