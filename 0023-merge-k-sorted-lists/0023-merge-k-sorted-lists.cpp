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
    ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val) {
            l1->next = MergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = MergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* DivideAndConquer(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];

        int mid = left + (right - left)/2;
        ListNode* l1 = DivideAndConquer(lists, left, mid);
        ListNode* l2 = DivideAndConquer(lists, mid+1, right);
        return MergeTwoSortedLists(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return DivideAndConquer(lists, 0, lists.size()-1);
    }
};