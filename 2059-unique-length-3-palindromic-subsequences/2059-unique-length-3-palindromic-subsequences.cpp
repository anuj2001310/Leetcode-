class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        vector<vector<int>> idx(26);

        for (int i = 0; i < s.size(); i++) {
            idx[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (idx[j].size() == 0)
                    continue;
                for (int k = 0; k < idx[i].size(); k++) {
                    if (idx[j][0] < idx[i][k] &&
                        idx[i][k] < idx[j][idx[j].size() - 1]) {
                        cnt++;
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};