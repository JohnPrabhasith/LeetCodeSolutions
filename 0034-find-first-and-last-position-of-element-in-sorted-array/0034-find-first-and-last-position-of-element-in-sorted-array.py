class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        def bin_search():
            l = 0
            r = n - 1

            while(l <= r):
                mid = (l + r) // 2

                if nums[mid] == target:
                    left = mid
                    while left >= 0 and nums[left] == target:
                        left -= 1
                    right = mid 
                    while right < n and nums[right] == target:
                        right += 1
                    return [left+1, right-1]
                elif nums[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1
            return [-1, -1]
        
        return bin_search()

        

            