#include <limits.h>
#include <stdio.h>
typedef long long ll;
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define FOR1(a, b, c) for (int a = b; a <= c; ++a)
#define Rep(i, n) FOR(i, 0, n)
#define Rep1(i, n) FOR1(i, 1, n)

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int odd = 0, cnt = INT_MAX;
    ll sum = 0;
    Rep(i, matrixSize) {
        Rep(j, (*matrixColSize)) {
            if (matrix[i][j] < 0)
                odd++;
            sum += fabs(matrix[i][j]);
            cnt = fmin(cnt, fabs(matrix[i][j]));
        }
    }
    if (odd & 1)
        return sum - 2 * fabs(cnt);
    return sum;
}