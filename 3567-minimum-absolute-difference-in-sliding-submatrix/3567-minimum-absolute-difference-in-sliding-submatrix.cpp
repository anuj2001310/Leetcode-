using vi = vector<int>;
using vvi = vector<vi>;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)
#define All(x) begin(x), end(x)
#define SORT(x) sort(All(x))
#define MAX std::numeric_limits<int>::max()

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vvi res(m - k + 1, vi(n - k + 1));
        Rep(i, 0, m - k + 1, 1) {
            Rep(j, 0, n - k + 1, 1) {
                vi kgrid;
                Rep(x, i, i + k, 1) {
                    Rep(y, j, j + k, 1) kgrid.push_back(grid[x][y]);
                }

                int kmin = MAX;
                SORT(kgrid);
                Rep(t, 1, size(kgrid), 1) {
                    if (kgrid[t] == kgrid[t - 1])
                        continue;

                    kmin = fmin(kmin, kgrid[t] - kgrid[t - 1]);
                }

                if (kmin != MAX)
                    res[i][j] = kmin;
            }
        }
        return res;
    }
};