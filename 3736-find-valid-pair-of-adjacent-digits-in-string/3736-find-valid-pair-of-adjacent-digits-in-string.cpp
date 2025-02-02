class Solution {
public:
    string findValidPair(string s) {
        array<int, 10> arr;
        for (auto& ch : s)
            arr[ch - '0']++;
        int n = s.length();
        string ans = "";
        for (int i = 1; i < n; i++) {
            int cur = s[i] - '0';
            int pre = s[i - 1] - '0';
            if (pre == arr[pre] and cur == arr[cur] and pre != cur)
                return ans + s[i - 1] + s[i];
        }
        return ans;
    }
};