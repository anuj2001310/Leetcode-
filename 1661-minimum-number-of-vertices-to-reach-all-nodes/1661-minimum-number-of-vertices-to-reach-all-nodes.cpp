class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[v]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};