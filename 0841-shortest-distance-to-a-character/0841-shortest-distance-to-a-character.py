class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        res = [0] * n
        indices = [i for i in range(n) if s[i] == c]
        for i in range(n):
            dis = inf
            for d in indices:
                dis = min(dis, fabs(i - d))
            res[i] = int(dis)
        return res