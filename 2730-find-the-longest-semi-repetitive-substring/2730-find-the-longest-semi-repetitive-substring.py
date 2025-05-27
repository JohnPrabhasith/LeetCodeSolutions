class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        l = 0
        r = 0
        n = len(s)
        maxCount = 0
        countAdjPairs = 0

        while r < n:
            
            if r > 0 and s[r] == s[r-1]:
                countAdjPairs += 1
            
            while countAdjPairs > 1:
                if s[l] == s[l+1]:
                    countAdjPairs -= 1
                l += 1
            
            maxCount = max(maxCount, r - l + 1)
            r += 1
        
        return maxCount
