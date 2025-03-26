class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr(m * n, 0);
        
        int index = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[index++] = grid[i][j];
            }
        }

        int base = arr[0] % x;
        for (auto& num : arr) {
            if (num % x != base) {
                return -1;  
            }
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() >> 1]; 

        int op = 0;
        for (auto& num : arr) {
            op += fabs(num - median) / x;
        }
        
        return op;
    }
};