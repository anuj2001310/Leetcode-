class Solution:
    def findLonelyPixel(self, p: List[List[str]]) -> int:
        n, m = len(p), len(p[0])
        rows = [0 for _ in range(n)]
        cols = [0 for _ in range(m)]

        for i in range(n):
            for j in range(m):
                if p[i][j] == 'B':
                    rows[i] += 1
                    cols[j] += 1
        
        return sum(1 for i in range(n) for j in range(m) if p[i][j] == 'B' and rows[i] == 1 and cols[j] == 1)