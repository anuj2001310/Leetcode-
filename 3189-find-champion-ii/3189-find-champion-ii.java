class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] inDeg = new int[n];
        for (int i = 0; i < edges.length; ++i) {
            int v = edges[i][1];
            inDeg[v]++;
        }

        int cnt = 0, ans = -1;
        for (int i = 0; i < inDeg.length; ++i) {
            if (inDeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
}