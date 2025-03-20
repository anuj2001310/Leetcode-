class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0, ans = 0, r = 0, n = s.length();
        for (; r < n; ++r) {
            map[s[r]]++;
            while (map[s[r]] >= 2)
                map[s[l++]]--;
            ans = fmax(ans, r - l + 1);
        }
        return ans;
    }
};