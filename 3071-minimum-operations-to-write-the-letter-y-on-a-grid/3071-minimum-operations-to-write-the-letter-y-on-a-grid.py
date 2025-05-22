class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def solve(y, notY):
            count = 0
            for i in range(n):
                for j in range(n):
                    if ((i <= n//2 and (i == j or (i + j == (n-1)))) or 
                        (i > n//2 and j == n//2)):
                        if grid[i][j] != y:
                            count += 1
                    else:
                        if grid[i][j] != notY:
                            count += 1
            return count
        
        return min({
            solve(0, 1), solve(0, 2), 
            solve(1, 0), solve(2, 0), 
            solve(1, 2), solve(2, 1)
        })

        