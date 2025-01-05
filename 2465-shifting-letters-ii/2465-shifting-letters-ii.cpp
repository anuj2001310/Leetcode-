class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff(n + 1, 0);

        for (auto& shift : shifts) {
            int s = shift[0];
            int e = shift[1];
            int d = shift[2];
            if (d == 1) {
                diff[s]++;
                diff[e + 1]--;
            } else {
                diff[s]--;
                diff[e + 1]++;
            }
        }
        // Suffix Sum calculate
        for (int i = 1; i < n + 1; i++)
            diff[i] += diff[i - 1];

        string res;
        for (uint i = 0; i < n; i++) {
            int cnt = diff[i] % 26;
            if (cnt < 0)
                cnt = 26 + cnt;
            char curr = char((s[i] - 'a' + cnt) % 26 + 97);
            res.push_back(curr);
        }
        return res;
    }
};