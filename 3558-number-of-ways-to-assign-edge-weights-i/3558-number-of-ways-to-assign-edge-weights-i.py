class Solution:
    def assignEdgeWeights(self, e: List[List[int]]) -> int:
        g = defaultdict(list)
        for v, u in map(sorted, e):
            g[v].append(u)

        f = lambda n, p: max([f(q, n) + 1 for q in g[n] if q != p] + [0])

        return pow(2, f(1, 0) - 1, 10**9 + 7)
