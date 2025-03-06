class Solution:
    def coloredCells(self, n: int) -> int:
        ans = 1
        i = 0

        # if n == 1 or n == 0:
        #     return n
        
        for a in range(n):
            ans += i 
            i += 4
            n -= 1
        return ans