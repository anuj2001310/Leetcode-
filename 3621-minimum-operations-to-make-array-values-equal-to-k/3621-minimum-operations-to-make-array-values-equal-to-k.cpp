class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        array<int, 101> set;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < k)
                return -1;
            else if (nums[i] > k)
                set[nums[i]]++;
        }

        int cnt = 0;
        for (int i = 0; i < 101; ++i)
            if (set[i])
                cnt++;
        return cnt;
    }
};