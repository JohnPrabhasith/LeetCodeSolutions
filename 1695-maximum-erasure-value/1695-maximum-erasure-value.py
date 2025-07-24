class Solution:
    def maximumUniqueSubarray(self, arr: List[int]) -> int:
        l, r = 0, 0
        n = len(arr)
        mp = {}
        ans = 0
        temp = 0

        while r < n:
            if arr[r] in mp:
                mp.pop(arr[l])
                temp -= arr[l]
                l += 1
            else:
                mp[arr[r]] = 1
                temp += arr[r]
                r += 1
            ans = max(ans, temp)
            
        return ans
