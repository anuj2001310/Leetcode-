class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = []
        res = 0
        m = len(edges)
        for i in range (m + 1):
            adj.append([])
        
        for i in range (m):
            u = edges[i][0]
            v = edges[i][1]
            adj[u].append(v)
            adj[v].append(u)
        
        vis = [False for _ in range (n)]

        def helper(node):
            nonlocal res
            if vis[node]:
                return 0
            vis[node] = True
            s = values[node]
            for neigh in adj[node]:
                s += helper (neigh)
            
            if s % k == 0:
                res += 1
                return 0
            return s
        
        helper (0)
        return res