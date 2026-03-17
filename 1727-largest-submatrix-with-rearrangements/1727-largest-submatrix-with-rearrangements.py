class Solution:
    def largestSubmatrix(self, matrix: list[list[int]]) -> int:
        if not matrix: 
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        max_area = 0

        for row in matrix:
            # build heights
            for j in range(n):
                heights[j] = heights[j] + 1 if row[j] else 0
            # sort heights in descending order to simulate column reordering
            sorted_heights = sorted(heights, reverse=True)
            for j in range(n):
                max_area = max(max_area, sorted_heights[j] * (j + 1))
        return max_area