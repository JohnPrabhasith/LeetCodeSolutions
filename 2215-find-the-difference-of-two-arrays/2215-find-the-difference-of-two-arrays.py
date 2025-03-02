class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        left = set(nums1)
        right = set(nums2)
        
        return [list(left - right), list(right - left)]