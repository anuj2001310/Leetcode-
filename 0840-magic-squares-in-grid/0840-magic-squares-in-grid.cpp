#pragma GCC optimize("O2")
#include <bits/stdc++.h>

class Solution {
    inline bool isMagic(char i, char j, char a, char b, char c, char d,
                        vector<vector<int>>& grid) {
        return (a + grid[i - 1][j] + b == 15) &&
               (a + grid[i][j - 1] + c == 15) &&
               (b + grid[i][j + 1] + d == 15) && (c + grid[i + 1][j] + d == 15);
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (r < 3 || c < 3)
            return 0;

        int cnt = 0;
        for (char i = 1; i < r - 1; i++) {
            for (char j = 1; j < c - 1; j++) {
                if (grid[i][j] != 5)
                    continue;
                char a = grid[i - 1][j - 1], b = grid[i - 1][j + 1],
                     c = grid[i + 1][j - 1], d = grid[i + 1][j + 1];
                uint16_t once = ((1 << 2) | (1 << 4) | (1 << 6) | (1 << 8)) ^
                                ((1 << a) | (1 << b) | (1 << c) | (1 << d));
                // check diagonals & center, numbers in corner are even
                if (once == 0 && (a & 1) == 0 && a + d == 10 && (b & 1) == 0 &&
                    b + c == 10)
                    cnt += isMagic(i, j, a, b, c, d, grid);
            }
        }
        return cnt;
    }
};