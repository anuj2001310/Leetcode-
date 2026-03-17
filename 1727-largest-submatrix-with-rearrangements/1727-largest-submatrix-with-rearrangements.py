class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:

        rows = len(matrix)
        cols = len(matrix[0])
        ans = 0
        for r in range(rows):
            for c in range(cols):
                if r > 0:
                    matrix[r][c] = (1 + matrix[r - 1][c]) if matrix[r][c] > 0 else 0
            # whole column is iterated
            # now sort it
            temp = sorted(matrix[r], reverse=True)
            print(temp)
            for i in range(cols):
                ans = max(ans, ((i + 1) * temp[i]))
        return ans
