class Solution:
    def fib(self, n: int) -> int:
        x = 0
        y = 1

        for i in range(n-1):
            temp = x
            x = y
            y = temp + y
        return y
            