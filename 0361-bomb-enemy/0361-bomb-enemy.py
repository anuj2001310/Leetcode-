from collections import defaultdict


class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dprows = [[0] for _ in range(m)]
        dpcols = [[0] for _ in range(n)]
        for i in range(m):
            for j in range(n):

                if grid[i][j] == "E":

                    dprows[i][-1] += 1
                    dpcols[j][-1] += 1
                elif grid[i][j] == "W":
                    dprows[i].append(0)
                    dpcols[j].append(0)

        rowidx = [0] * m
        colidx = [0] * n

        result = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "0":
                    result = max(result, dprows[i][rowidx[i]] + dpcols[j][colidx[j]])

                elif grid[i][j] == "W":
                    rowidx[i] += 1
                    colidx[j] += 1

        return result
