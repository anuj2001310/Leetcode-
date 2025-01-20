class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        temp = [[] for _ in range(n * m + 1)]
        for i in range(n):
            for j in range(m):
                temp[mat[i][j]] = [i, j]

        row, col = [0] * n, [0] * m
        for i in range(n * m):
            [r, c] = temp[arr[i]]
            row[r] += 1
            col[c] += 1
            if row[r] == m or col[c] == n:
                return i
        return -1