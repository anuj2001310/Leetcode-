

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        
        // Use a min-priority queue to explore the path with the smallest maximum elevation first.
        // The queue stores {max_elevation, row, col}.
        using T = std::tuple<int, int, int>;
        std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;
        
        // visited array to keep track of cells that have been processed.
        std::vector<std::vector<bool>> seen(n, std::vector<bool>(n, false));
        
        // Start at (0, 0) with the initial time being the elevation at that cell.
        minHeap.emplace(grid[0][0], 0, 0);
        seen[0][0] = true;
        
        // Directions for the 4-directional movement.
        std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (!minHeap.empty()) {
            auto [t, r, c] = minHeap.top();
            minHeap.pop();

            // If we've reached the destination, we are done.
            if (r == n - 1 && c == n - 1) {
                return t;
            }

            // Explore neighbors.
            for (const auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check for out-of-bounds.
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    continue;
                }
                
                // If the neighbor has already been visited, skip it.
                if (seen[nr][nc]) {
                    continue;
                }

                // The new "time" for the path is the maximum of the current time
                // and the elevation of the new cell.
                int new_t = std::max(t, grid[nr][nc]);
                
                // Push the neighbor into the priority queue.
                minHeap.emplace(new_t, nr, nc);
                seen[nr][nc] = true;
            }
        }
        
        // This line should be unreachable for a valid grid,
        // but can be included for robustness.
        return -1;
    }
};
