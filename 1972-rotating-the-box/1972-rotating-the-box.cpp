#include <bits/stdc++.h>
using namespace std;
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int n = (int)box.size(), m = (int)box[0].size();
        vector ret(m, vector<char>(n, '.'));
        Rep(i, n) {
            const int c = n - i - 1;
            int p = m - 1;
            for (int j = m - 1; j >= 0; j--)
                if (box[i][j] == '#')
                    ret[p--][c] = '#';
                else if (box[i][j] == '*') {
                    ret[j][c] = '*';
                    p = j - 1;
                }
        }
        return ret;
    }
};