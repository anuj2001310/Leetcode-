class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        sm, cbt = 0, 1
        mini = float('inf')
        
        n = len(matrix)
        m = len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] < 0:
                    cbt += 1
                sm += abs(matrix[i][j])
                mini = min(mini, abs(matrix[i][j]))
        
        if cbt & 1 == 0:
            return sm - 2 * abs(mini)
        return sm