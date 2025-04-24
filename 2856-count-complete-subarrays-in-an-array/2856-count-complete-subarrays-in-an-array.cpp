class Solution {
private:
    int help(vector<int>& nums, int k, int n) {
        unordered_map<int, int> mp;
        int l = 0, cnt = 0;
        for (int r = 0; r < n; r++) {
            if (!mp[nums[r]]++)
                k--;
            while (k < 0)
                if (!--mp[nums[l++]])
                    k++;
            cnt += r - l + 1;
        }
        return cnt;
    }

public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        vector<int>::iterator it;
        it = nums.begin();
        for (; it != nums.end(); ++it)
            st.insert(*it);
        int k = st.size(), n = nums.size();

        return help(nums, k, n) - help(nums, k - 1, n);
    }
};