class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        x = 0
        y = 1
        temp = -1
        for i in range(n-1):
            temp = x
            x = y
            y = temp + y
        return y
            