class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        left = 0
        ans, b = float('inf'), 0
        while left < n:
            
            if blocks[left] == 'B':
                b += 1
            if left >= k-1:
                ans = min(ans, k-b)
                if blocks[left - k + 1] == 'B':
                    b -= 1
            left += 1
        return ans