class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int num_len = nums.size();
        vector<int> hash(10001, 0);
        int n = (num_len >> 1);
        for (int i = 0; i < num_len; ++i) {
            hash[nums[i]]++;
            if (hash[nums[i]] >= n)
                return nums[i];
        }
        return -1;
    }
};