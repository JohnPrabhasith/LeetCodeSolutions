class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        s = set()
        m = len(matrix)
        n = len(matrix[0])
        
        for i in range(m):
            for j in range(n):
                if(matrix[i][j] == 0):
                    s.add(i)
                    s.add(j)
        
        for i in range(m):
            for j in range(n):
                if i in s or j in s:
                    matrix[i][j] = 0
        

        