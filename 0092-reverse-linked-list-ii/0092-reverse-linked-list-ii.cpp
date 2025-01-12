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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
if (!head || left == right) return head; // Edge case

    ListNode dummy(0); // Dummy node to simplify edge cases
    dummy.next = head;
    ListNode* prev = &dummy;

    // Step 1: Move `prev` to the node just before the `left` position
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    // Step 2: Reverse the sublist
    ListNode* curr = prev->next; // First node to be reversed
    ListNode* next = nullptr;

    for (int i = 0; i < right - left; ++i) {
        next = curr->next; // Store next node
        curr->next = next->next; // Reverse the link
        next->next = prev->next; // Insert `next` at the beginning of the reversed section
        prev->next = next; // Move `prev`'s next to `next`
    }

    return dummy.next; // Return the new head of the list
    }
};