class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> map;
        int n = dominoes.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int u = dominoes[i][0];
            int v = dominoes[i][1];
            if (u > v)
                swap(u, v);

            cnt += map[{u, v}];
            map[{u, v}]++;
        }
        return cnt;
    }
};