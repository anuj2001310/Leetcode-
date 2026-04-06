class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        vector<int> digits(10, 0), chars(26, 0);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                digits[s[i] - '0']++;
            else
                chars[s[i] - 'a']++;
        }

        for (int i = 0; i < 13; i++) {
            int fc = chars[i];
            int fm = chars[25 - i];

            sum += fabs(fc - fm);
        }

        for (int i = 0; i < 5; i++) {
            int fc = digits[i];
            int fm = digits[9 - i];

            sum += fabs(fc - fm);
        }
        return sum;
    }
};