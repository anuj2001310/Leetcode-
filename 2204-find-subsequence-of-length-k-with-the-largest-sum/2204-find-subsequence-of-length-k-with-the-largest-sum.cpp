class Solution {
    using pii = pair<int, int>;

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pii> vec;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i)
            vec.push_back({nums[i], i});

        sort(vec.begin(), vec.end(),
             [&](const pii& a, const pii& b) { return a.first > b.first; });

        map<int, int> map;

        for (int i = 0; i < k; i++)
            map[vec[i].second] = vec[i].first;

        vector<int> ans;
        for (auto& [_, val] : map)
            ans.push_back(val);

        return ans;
    }
};