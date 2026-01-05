#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int odd = 0, mini = INT_MAX;
        ll sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        Rep(i, n) {
            Rep(j, m) {
                sum += fabs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    odd++;
                matrix[i][j] = fabs(matrix[i][j]);
                mini = fmin(mini, matrix[i][j]);
            }
        }
        // cout << mini << endl;
        //  If - negative count is odd then just simply return total sum -
        //  minimum element of matrix
        if (odd & 1)
            return sum - 2 * abs(mini);
        return sum;
    }
};