class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n, 0);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            inDeg[v]++;
        }
        int cnt = 0, ans = -1;
        for (int i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};