class Solution:
    def findCircleNum(self, arr: List[List[int]]) -> int:
        n = len(arr)
        visited = set()
        count = 0

        def dfs(i):
            visited.add(i)
            for j in range(n):
                if j not in visited and arr[i][j] == 1:
                    dfs(j)

        for i in range(n):
            if i not in visited:
                visited.add(i)
                count += 1
                dfs(i)
        return count