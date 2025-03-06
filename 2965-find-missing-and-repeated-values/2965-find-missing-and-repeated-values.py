class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        mode = -1

        n = len(grid) 
        total = ((n**2) * ((n**2)+1)) // 2
        s = set()
        sum = 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] in s:
                    mode = grid[i][j]
                s.add(grid[i][j])
                sum += grid[i][j]

        return [mode, total - (sum - mode)]