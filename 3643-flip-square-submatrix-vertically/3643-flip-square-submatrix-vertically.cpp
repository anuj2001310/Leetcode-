using vi = vector<int>;
using vvi = vector<vi>;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        Rep(r, x, x + k / 2, 1) {
            int minr = x + k - 1 - (r - x);
            Rep(j, y, y + k, 1) 
                swap(grid[r][j], grid[minr][j]);
        }
        return grid;
    }
};