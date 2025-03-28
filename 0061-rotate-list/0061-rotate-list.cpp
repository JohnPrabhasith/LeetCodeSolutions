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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        int n = 1;

        while(temp->next != nullptr) {
            n++;
            temp = temp->next;
        }
        
        temp->next = head;

        k = k%n;
        int new_n = n-k;
        temp = head;

        for(int i=1;i<new_n;i++) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};