#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

class Solution {
    using ll = long long;
    using os = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        ll ans = 0;
        os set;
        for (auto& num : nums)
            num = (num == target) ? 1 : -1;
        int prefix = 0;
        set.insert(0);
        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            ans += set.order_of_key(prefix);
            set.insert(prefix);
        }
        return ans;
    }
};