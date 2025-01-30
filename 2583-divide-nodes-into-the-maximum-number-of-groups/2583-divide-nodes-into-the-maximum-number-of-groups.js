/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
function magnificentSets(n, edges) {
    // Build adjacency list
    const graph = Array.from({ length: n + 1 }, () => []);
    for (const [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    // Find connected components using DFS
    const visited = new Set();
    const components = [];

    function dfs(node, component) {
        if (visited.has(node)) return;
        visited.add(node);
        component.push(node);
        for (const nei of graph[node]) {
            dfs(nei, component);
        }
    }

    // Get all components
    for (let i = 1; i <= n; i++) {
        if (!visited.has(i)) {
            const component = [];
            dfs(i, component);
            components.push(component);
        }
    }

    // BFS to find max groups for a component starting from a specific node
    function bfs(start) {
        const dist = new Array(n + 1).fill(-1);
        const queue = [start];
        dist[start] = 0;
        let maxGroup = 1;

        // Check bipartite property and find max group
        while (queue.length) {
            const node = queue.shift();
            maxGroup = Math.max(maxGroup, dist[node] + 1);

            for (const nei of graph[node]) {
                if (dist[nei] === -1) {
                    dist[nei] = dist[node] + 1;
                    queue.push(nei);
                } else if (Math.abs(dist[nei] - dist[node]) !== 1) {
                    return -1;
                }
            }
        }

        return maxGroup;
    }

    // Process each component
    let totalGroups = 0;

    for (const component of components) {
        let maxComponentGroups = -1;

        // Try each node as starting point
        for (const node of component) {
            const groups = bfs(node);
            if (groups === -1) return -1;
            maxComponentGroups = Math.max(maxComponentGroups, groups);
        }

        totalGroups += maxComponentGroups;
    }

    return totalGroups;
}