public class Solution {
    public int FindLonelyPixel(char[][] p) {
        int n = p.Length, m = p[0].Length;
        var r = new int[n];
        var c = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] == 'B') {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        var cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (p[i][j] == 'B' && r[i] == 1 && c[j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
}