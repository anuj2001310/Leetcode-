class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int r = 0;
        int ans = std::numeric_limits<int>::max();

        auto reverse = [&](int num) -> int {
            int r = 0;
            while (num) {
                r = r * 10 + num % 10;
                num /= 10;
            }
            return r;
        };
        
        for (; r < n; ++r) {
            int num = nums[r];
            if (map.find(num) != map.end())
                ans = fmin(ans, r - map[num]);
            int rev = reverse(nums[r]);
            map[rev] = r;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};