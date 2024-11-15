class Solution {
private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }

public:
    bool areNumbersAscending(string s) {
        vector<int> nums;
        string t = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                t += s[i];
                while (i + 1 < s.length() and
                       (s[i + 1] >= '0' and s[i + 1] <= '9')) {
                    t += s[i + 1];
                    i++;
                }
                nums.push_back(stoi(t));
            } else
                t = "";
        }
        return isSorted(nums);
    }
};

static const char a = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}();