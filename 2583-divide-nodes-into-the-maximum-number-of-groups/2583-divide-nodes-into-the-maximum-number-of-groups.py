class Solution(object):
    def magnificentSets(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(n + 1)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        color = [-1]*(n+1)
        
        # Check bipartite and also group nodes by component
        def bfs_check_bipartite(start):
            queue = deque([start])
            color[start] = 0
            comp_nodes = [start]
            while queue:
                u = queue.popleft()
                for w in graph[u]:
                    if color[w] == -1:
                        color[w] = 1 - color[u]
                        comp_nodes.append(w)
                        queue.append(w)
                    elif color[w] == color[u]:
                        return False, []
            return True, comp_nodes

        # We'll store components
        components = []
        for i in range(1, n+1):
            if color[i] == -1:
                is_bip, comp_nodes = bfs_check_bipartite(i)
                if not is_bip:
                    return -1
                components.append(comp_nodes)

        # Function to run BFS restricted to a component's nodes and return max distance
        def max_bfs_distance_from_node(start, comp_set):
            dist = {start:0}
            q = deque([start])
            visited = {start}
            max_dist = 0
            while q:
                u = q.popleft()
                for w in graph[u]:
                    if w in comp_set and w not in visited:
                        visited.add(w)
                        dist[w] = dist[u] + 1
                        max_dist = max(max_dist, dist[w])
                        q.append(w)
            return max_dist

        total_groups = 0
        for comp_nodes in components:
            comp_set = set(comp_nodes)
            # Try BFS from each node in the component to find the max layering
            best_layers = 0
            for node in comp_nodes:
                d = max_bfs_distance_from_node(node, comp_set)
                # layers = distance + 1
                if d + 1 > best_layers:
                    best_layers = d + 1
            total_groups += best_layers

        return total_groups