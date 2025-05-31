class Solution:
    def gridGame(self, arr: List[List[int]]) -> int:
        n = len(arr[0])
        ans = float("inf")
        topSum = sum(arr[0])
        bottomSum = 0

        for i in range(n):
            topSum -= arr[0][i]
            ans = min(ans, max(topSum, bottomSum))
            bottomSum += arr[1][i]

        return ans