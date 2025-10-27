class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        unordered_set<int> indices;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c)
                indices.insert(i);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            int dis = std::numeric_limits<int>::max();
            auto it = indices.begin();
            for (; it != indices.end(); ++it)
                dis = fmin(dis, fabs(i - *it));
            ans[i] = dis;
        }
        return ans;
    }
};