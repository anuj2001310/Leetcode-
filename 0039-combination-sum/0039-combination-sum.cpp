class Solution {
private:
    void find(int idx, vector<int>& candidates, int target,
              vector<vector<int>>& ans, vector<int>& ds) {
        if (idx == candidates.size()) {
            if (target == 0)
                ans.push_back(vector<int>(ds));
            return ;
        }
        if (candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            find(idx, candidates, target - candidates[idx], ans, ds);
            ds.pop_back();
        }
        find(idx + 1, candidates, target, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(0, candidates, target, ans, ds);
        return ans;
    }
};