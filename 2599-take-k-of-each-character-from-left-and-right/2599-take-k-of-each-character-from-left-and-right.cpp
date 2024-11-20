class Solution {
    inline char getC(string& s, int i) { return s[i % s.size()]; }

public:
    int takeCharacters(string s, int k) {
        vector<int> count(255, 0);
        int n = s.size();
        int start = n;
        while (true) {
            if (count['a'] >= k && count['b'] >= k && count['c'] >= k)
                break;
            start--;
            if (start < 0)
                break;

            count[s[start]]++;
        }

        if (start < 0)
            return -1;

        int end = n;
        int ans = end - start;
        while (start <= n - 1) {
            count[s[start]]--;
            start++;

            while (count['a'] < k || count['b'] < k || count['c'] < k) {
                count[getC(s, end)]++;
                end++;
            }

            ans = fmin(ans, end - start);
        }
        return ans;
    }
};