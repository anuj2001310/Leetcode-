class Solution {
    using ll = long long;
    using vll = vector<ll>;
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<ll> res;
        for (const auto& x : nums) {
            ll cur = x;
            while (!res.empty() && res.back() == cur) {
                cur *= 2;
                res.pop_back();
            }
            res.push_back(cur);
        }
        return res;
    }
};