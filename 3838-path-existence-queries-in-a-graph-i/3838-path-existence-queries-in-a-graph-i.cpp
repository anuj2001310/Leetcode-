class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q, false);
        vector<int> comp(n, 0);
        int cnt = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                comp[i] = cnt;
            else
                comp[i] = ++cnt;
        }
        
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            bool flag = (comp[u] == comp[v]);
            ans[i] = flag;
        }
        return ans;
    }
};