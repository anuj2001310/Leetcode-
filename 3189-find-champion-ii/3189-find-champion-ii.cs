public class Solution {
    public int FindChampion(int n, int[][] edges) {
        int[] inDeg = new int[n];
        for (var i = 0; i < edges.Length; ++i) {
            int v = edges[i][1];
            inDeg[v]++;
        }
        int cnt = 0, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : - 1;
    }
}