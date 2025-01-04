class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])

        row = [False for _ in range(n)]
        col = [False for _ in range(m)]

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        
        for i in range(n):
            for j in range(m):
                if row[i] or col[j]:
                    matrix[i][j] = 0