class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        V = numCourses
        adj = [[] for _ in range(V)]
        indegree = [0 for _ in range(V)]

        for pre in prerequisites:
            u, v = pre[0], pre[1]
            adj[u].append(v)
            indegree[v] += 1
        
        cnt = 0
        q = deque([x for x in range(V) if indegree[x] == 0])
        while q:
            node = q.popleft()
            cnt += 1
            for neigh in adj[node]:
                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    q.append(neigh)

        return cnt == V
        