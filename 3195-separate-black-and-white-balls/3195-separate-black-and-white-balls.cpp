class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, sw = 0;
        for (auto& ch : s) {
            if (ch == '1')
                sw++;
            else
                ans += sw;
        }
        return ans;
    }
};