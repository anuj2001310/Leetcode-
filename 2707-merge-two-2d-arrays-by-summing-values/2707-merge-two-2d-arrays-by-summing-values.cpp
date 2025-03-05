class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        array<int, 1001> help;
        for (int i = 0; i < n; ++i) {
            int idx = nums1[i][0];
            int val = nums1[i][1];
            help[idx] += val;
        }
        for (int i = 0; i < m; ++i) {
            int idx = nums2[i][0];
            int val = nums2[i][1];
            help[idx] += val;
        }
        for (int i = 0; i < help.size(); ++i)
            if (help[i])
                ans.push_back({i, help[i]});
        
        return ans;
    }
};