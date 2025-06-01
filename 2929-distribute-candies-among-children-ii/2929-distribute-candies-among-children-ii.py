class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def sum(s):
            if s < 0: return 0
            return ((s + 1) * (s + 2)) // 2
        
        return sum(n) \
               -3*sum(n-limit-1) \
               +3*sum(n-2*(limit+1)) \
               -sum(n-3*(limit+1)) 