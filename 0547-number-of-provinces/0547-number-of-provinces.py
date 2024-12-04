class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        adj = {}
        V = len(isConnected)
        for i in range(V):
            adj[i] = []
        
        vis = [False for _ in range(V)]
        for i in range(V):
            for j in range(V):
                if isConnected[i][j] == 1 and i != j:
                    adj[i].append(j)
                    adj[j].append(i)
        
        def dfs (node):
            vis[node] = True
            for neigh in adj[node]:
                if not vis[neigh]:
                    dfs (neigh)
        

        cnt = 0
        for i in range(V):
            if not vis[i]:
                cnt += 1
                dfs (i)
        return cnt