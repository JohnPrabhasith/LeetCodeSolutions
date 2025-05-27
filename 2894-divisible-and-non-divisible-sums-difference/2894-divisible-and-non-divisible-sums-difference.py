class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        inclusiveSum = 0
        exclusiveSum = 0

        # if n == 1:
        #     return 1
        for i in range(1, n+1):
            if i % m != 0:
                inclusiveSum += i
            else:
                exclusiveSum += i
        
        return inclusiveSum - exclusiveSum