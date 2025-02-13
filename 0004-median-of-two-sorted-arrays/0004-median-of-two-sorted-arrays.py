class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        arr = nums1 + nums2
        arr = sorted(arr)
        mid = len(arr)//2
        if len(arr) % 2 == 1:
            return arr[mid]
        else:
            return (arr[mid] + arr[mid - 1])/2
