class Solution:
    def candy(self, arr: List[int]) -> int:
        n = len(arr)
        if n <= 0: return n
        ans = n * [1]
        
        for i in range(1, n):
            if arr[i] > arr[i-1]:
                ans[i] = ans[i-1] + 1
        
        for i in range(n-2, -1, -1):
            if (arr[i] > arr[i+1]):
                ans[i] = max(ans[i], ans[i+1]+1)
        
        count = 0
        for i in range(n):
            count += ans[i]
    
        return count
            