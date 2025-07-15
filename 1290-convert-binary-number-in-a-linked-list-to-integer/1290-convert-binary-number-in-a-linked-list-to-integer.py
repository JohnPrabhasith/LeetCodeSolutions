# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        size = 0
        temp = head
        while temp:
            size += 1
            temp = temp.next
        
        temp = head
        ans = 0
        while temp:
            size -= 1
            if temp.val == 1:
                ans += 2**size
            temp = temp.next
        return ans


        