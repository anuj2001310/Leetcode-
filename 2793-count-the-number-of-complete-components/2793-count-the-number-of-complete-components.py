class Solution(object):
    def countCompleteComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        adj = {}
        for i in range(n):
            adj[i] = []
        
        for edge in edges:
            u = edge[0]
            v = edge[1]

            adj[u].append(v)
            adj[v].append(u)

        cnt = 0
        vis = [False for _ in range(n)]

        for i in range(n):
            if not vis[i]:
                comp = []
                q = deque()

                vis[i] = True
                q.append(i)
                
                while q:
                    node = q.popleft()
                    comp.append(node)

                    for neigh in adj[node]:
                        if not vis[neigh]:
                            vis[neigh] = True
                            q.append(neigh)
                flag = True
                for ele in comp:
                    if len(adj[ele]) != len(comp) - 1:
                        flag = not flag
                        break
                if flag:
                    cnt += 1
        

        #print(adj)
        return cnt