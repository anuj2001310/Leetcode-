class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        path = []
        vis = [False for _ in range(n)]

        def dfs (node : int) -> None:
            vis[node] = True
            path.append(node)
            if node == n - 1:
                ans.append([x for x in path])
            
            for neigh in graph[node]:
                if not vis[neigh]:
                    dfs (neigh)
            
            vis[node] = False
            path.pop()
        
        dfs (0)
        return ans