class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        array<int, 26> end;

        for (int i = 0; i < n; ++i) {
            int key = s[i] - 'a';
            end[key] = i;
        }
        int prev = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            int key = s[i] - 'a';
            if (end[key] > last)
                last = end[key];
            if (i == last) {
                ans.push_back(i - prev);
                prev = i;
            }
        }
        return ans;
    }
};