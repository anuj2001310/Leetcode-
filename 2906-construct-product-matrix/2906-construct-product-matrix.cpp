using vi = vector<int>;
#define Rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;
        const int MOD = 12345;

        vi flat(size);

        Rep(i, 0, n, 1) { 
            Rep(j, 0, m, 1)
                flat[i * m + j] = grid[i][j] % MOD;
        }

        vi prefix(size, 1), suffix(size, 1);

        Rep(i, 1, size, 1)
            prefix[i] = (prefix[i - 1] * flat[i - 1]) % MOD;

        for (int i = size - 2; i >= 0; i--)
            suffix[i] = (suffix[i + 1] * flat[i + 1]) % MOD;

        Rep(i, 0, size, 1) 
            grid[i / m][i % m] = (prefix[i] * suffix[i]) % MOD;

        return grid;
    }
};