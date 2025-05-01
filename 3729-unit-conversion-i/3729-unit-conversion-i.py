class Solution(object):
    def baseUnitConversions(self, conversions):
        """
        :type conversions: List[List[int]]
        :rtype: List[int]
        """
        n = len(conversions)
        mod = 1000000007
        adj = [[] for _ in range(n + 1)]
        for conversion in conversions:
            f = conversion[0]
            t = conversion[1]
            r = conversion[2]
            adj[f].append((t, r))
        #print(adj)
        q = deque()
        q.append(0)
        
        ans = [-1 for _ in range(n + 1)]
        ans[0] = 1
        
        while q:
            top = q.popleft()
            for edge in adj[top]:
                if ans[edge[0]] == -1:
                    ans[edge[0]] = (ans[top] * edge[1]) % mod
                    q.append(edge[0])
        return ans