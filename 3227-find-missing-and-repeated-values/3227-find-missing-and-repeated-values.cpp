class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> result;
        int row = grid.size();
        int col = grid[0].size();
        int square = row * col;
        int arr[square + 1];
        for (int i = 0; i <= square; i++)
            arr[i] = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[grid[i][j]]++;
            }
        }
        for (int i = 1; i <= square; i++) {
            if (arr[i] == 1) {
                result.push_back(i);
                break;
            }
        }
        for (int i = 1; i <= square; i++) {
            if (arr[i] == -1){
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};