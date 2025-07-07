class Solution:
    def fib(self, n: int) -> int:
        curr, prev = 1, 0
        ans = 0
        for i in range(n):
            ans = prev + curr
            prev = curr
            curr = ans
        return prev