class Solution:
    def maxDifference(self, s: str) -> int:
        from collections import Counter

        mp = Counter(s)

        oddMax = 0 # a1
        evenMax = len(s) # a2

        for _, val in mp.items():
            if evenMax > val and val % 2 == 0:
                evenMax = val
            if oddMax < val and val % 2 != 0:
                oddMax = val
        
        return oddMax - evenMax
