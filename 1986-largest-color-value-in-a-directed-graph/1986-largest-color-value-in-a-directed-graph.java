class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        // Get the number of nodes in the graph
        int n = colors.length();

        // Initialize the graph as an adjacency list
        List<Integer>[] graph = new List[n];
        // Array to keep track of the indegree of each node
        int[] indegree = new int[n];
        // 2D array to count the maximum frequency of each color for each node
        int[][] colorCount = new int[n][26];

        // Initialize the graph
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // Build the graph and calculate indegrees
        for (int[] edge : edges) {
            int u = edge[0]; // Starting node of the edge
            int v = edge[1]; // Ending node of the edge
            graph[u].add(v); // Add the edge to the graph
            indegree[v]++; // Increment the indegree of the ending node
        }

        // Initialize a queue for processing nodes with no incoming edges
        Queue<Integer> queue = new LinkedList<>();
        // Add all nodes with zero indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i); // Add node to the queue
                colorCount[i][colors.charAt(i) - 'a']++; // Increment the color count for the starting node
            }
        }

        int visitedCount = 0; // Count of visited nodes
        int maxColorValue = 0; // Variable to track the maximum color value

        // Process nodes in the queue
        while (!queue.isEmpty()) {
            int node = queue.poll(); // Get the next node to process
            visitedCount++; // Increment the count of visited nodes

            // Update the maximum color value based on the current node's color counts
            for (int i = 0; i < 26; i++)
                maxColorValue = Math.max(maxColorValue, colorCount[node][i]);

            // Process each neighbor of the current node
            for (int neighbor : graph[node]) {
                indegree[neighbor]--; // Decrement the indegree of the neighbor
                // Update the color counts for the neighbor based on the current node
                for (int i = 0; i < 26; i++) 
                    colorCount[neighbor][i] = Math.max(colorCount[neighbor][i], colorCount[node][i]);

                // If the neighbor has no more incoming edges, add it to the queue
                if (indegree[neighbor] == 0) {
                    colorCount[neighbor][colors.charAt(neighbor) - 'a']++; // Increment the color count for the neighbor
                    queue.offer(neighbor); // Add the neighbor to the queue for processing
                }
            }
        }

        // If all nodes were visited, return the maximum color value; otherwise, return -1 (indicating a cycle)
        return visitedCount == n ? maxColorValue : -1;
    }
}
