class Solution {
    class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        pair[] temp = new pair[n * m + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                temp[mat[i][j]] = new pair(i, j);
        }

        int[] rows = new int[n];
        int[] cols = new int[m];
        for (int i = 0; i < n * m; ++i) {
            int r = temp[arr[i]].first;
            int c = temp[arr[i]].second;
            rows[r]++;
            cols[c]++;
            if (rows[r] == m || cols[c] == n)
                return i;
        }
        return -1;
    }
}