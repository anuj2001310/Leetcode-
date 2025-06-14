class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int i = 0;

        // Maximize
        while (i < s.size() && s[i] == '9')
            i++;
        if (i < s.size()) {
            char c = s[i];
            int j = 0;
            while (j < s.size()) {
                if (s[j] == c)
                    s[j] = '9';
                j++;
            }
        }
        int ans = stoi(s);

        // Minimize
        s = to_string(num);
        i = 0;
        while (i < s.size() && s[i] == '0')
            i++;
        if (i < s.size()) {
            char c = s[i];
            int j = 0;
            while (j < s.size()) {
                if (s[j] == c)
                    s[j] = '0';
                j++;
            }
        }

        ans -= stoi(s);
        return ans;
    }
};