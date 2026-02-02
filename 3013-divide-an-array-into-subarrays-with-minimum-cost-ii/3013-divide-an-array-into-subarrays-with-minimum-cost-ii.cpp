class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        typedef long long LL;
        int n = nums.size();
        LL ans = LLONG_MAX, sum = 0;
        set<pair<int, int>> lft, rht;
        for (int i = 1; i < n; ++i) {
            lft.insert({nums[i], i});
            sum += nums[i];
            if (lft.size() >= k) {
                auto it = *lft.rbegin();
                sum -= it.first;
                rht.insert(it);
                lft.erase(it);
            }
            if (i - dist > 0) {
                ans = min(ans, sum);
                pair<int, int> it = {nums[i - dist], i - dist};
                if (lft.count(it)) {
                    sum -= it.first;
                    lft.erase(it);
                    if (!rht.empty()) {
                        it = *rht.begin();
                        sum += it.first;
                        lft.insert(it);
                        rht.erase(it);
                    }
                } else
                    rht.erase(it);
            }
        }
        ans += nums[0];
        return ans;
    }
};