class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> help(n);
        for (int i = 0; i < n; i++)
            help[i] = {nums[i], i};
        
        sort(help.begin(), help.end(), [&](const auto& x, const auto& y) { 
            return x.first < y.first;
        });

        vector<int> res(n, 0);

        int prev = INT_MIN;
        vector<int> pos;
        for (int s = 0, e = 0; e < n;) {
            pos.push_back(help[e].second);
            prev = help[e].first;
            e++;

            if (e == n or help[e].first - prev > limit) {
                sort(pos.begin(), pos.end());
                for (auto idx : pos) 
                    res[idx] = help[s++].first;

                pos.clear();
            }
        }

        return res;
    }
};