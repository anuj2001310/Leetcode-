class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        vis = [False for _ in range(n)]
        adj = [[] for _ in range(n)]

        for edge in edges:
            u, v = edge[0], edge[1]

            adj[u].append(v)
            adj[v].append(u)
           
            
        def dfs (node: int) -> void:
            vis[node] = True

            for neigh in adj[node]:
                if not vis[neigh]:
                    dfs (neigh)
        
        cnt = 0
        for i in range(n):
            if not vis[i]:
                cnt += 1
                dfs (i)
        
        return cnt