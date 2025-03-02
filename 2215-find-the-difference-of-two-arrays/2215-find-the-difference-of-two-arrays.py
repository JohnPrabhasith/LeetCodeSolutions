class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        def returnArray(nums1: List[int], nums2: List[int])->List[int]:
            vec = []
            for num in nums1:
                if num not in nums2:
                    vec.append(num)
            return list(set(vec))
        
        ans = []
        ans.append(returnArray(nums1, nums2))
        ans.append(returnArray(nums2, nums1))

        return ans
        