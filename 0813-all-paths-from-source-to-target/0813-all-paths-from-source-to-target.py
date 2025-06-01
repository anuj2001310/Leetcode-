class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(graph)
        ans = []
        path = []
        vis = [False for _ in range(n)]

        def dfs (node):
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