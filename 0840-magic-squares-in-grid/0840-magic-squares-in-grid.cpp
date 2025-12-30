class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        vector<vvi> magic = {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
                             {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
                             {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
                             {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
                             {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
                             {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
                             {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
                             {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};

        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {

                // Center must be 5
                if (grid[i + 1][j + 1] != 5)
                    continue;

                for (auto& m : magic) {
                    bool ok = true;
                    for (int x = 0; x < 3 && ok; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (grid[i + x][j + y] != m[x][y]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};