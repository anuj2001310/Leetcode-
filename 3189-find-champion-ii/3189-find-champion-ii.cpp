class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[v]++;
        }

        int cnt = 0, ans = -1;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                cnt++;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};