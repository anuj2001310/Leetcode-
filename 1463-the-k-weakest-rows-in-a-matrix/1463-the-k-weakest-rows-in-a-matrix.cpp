class Solution {
    using pii = pair<int, int>;

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {sum, i}
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j])
                    sum += mat[i][j];
            }
            pq.push({sum, i});
        }
        vector<int> ans;
        while (k-- and !pq.empty()) {
            auto top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        return ans;
    }
};