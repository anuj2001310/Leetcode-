typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

class Solution {
    vpii st;

public:
    vector<int> leftmostBuildingQueries(vector<int>& hs,  vector<vector<int>>& qs) {
        int n = qs.size();
        vi ans(n, -1);
        vvpii es(hs.size());
        for (int i = 0; i < n; i++) {
            int x = qs[i][0];
            int y = qs[i][1];
            if (x > y)
                swap(x, y);
            if (hs[y] > hs[x] || x == y)
                ans[i] = y;
            else
                es[y].push_back({hs[x], i});
        }
        auto search = [&](int x) -> int {
            int l = 0;
            int r = st.size() - 1;
            int ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (st[m].first > x) {
                    ans = max(ans, m);
                    l = m + 1;
                } else
                    r = m - 1;
            }
            return ans;
        };
        for (int i = hs.size() - 1; i >= 0; i--) {
            int n1 = st.size();
            for (auto& [x, y] : es[i]) {
                int p = search(x);
                if (p < n1 and p >= 0)
                    ans[y] = st[p].second;
            }
            while (!st.empty() && st.back().first <= hs[i])
                st.pop_back();
            st.push_back({hs[i], i});
        }
        return ans;
    }
};