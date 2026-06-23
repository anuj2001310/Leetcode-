class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<vector<int>> nxt(m, vector<int>(3, 1));
        vector<vector<int>> cur(m, vector<int>(3));

        vector<int> pref(m), suff(m);

        for (int pos = n - 1; pos >= 1; pos--) {
            pref[0] = nxt[0][1];
            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + nxt[i][1];
                if (pref[i] >= MOD)
                    pref[i] -= MOD;
            }

            suff[m - 1] = nxt[m - 1][2];
            
            for (int i = m - 2; i >= 0; i--) {
                suff[i] = suff[i + 1] + nxt[i][2];
                if (suff[i] >= MOD)
                    suff[i] -= MOD;
            }

            for (int prev = 0; prev < m; prev++) {

                long long left = (prev > 0 ? pref[prev - 1] : 0);
                long long right = (prev < m - 1 ? suff[prev + 1] : 0);

                // trend = 1
                cur[prev][0] = (left + right) % MOD;

                // trend = 2
                cur[prev][1] = (prev == m - 1 ? 0 : suff[prev + 1]);

                // trend = 3
                cur[prev][2] = (prev == 0 ? 0 : pref[prev - 1]);
            }

            swap(cur, nxt);
        }

        long long ans = 0;

        // choose first element
        for (int i = 0; i < m; i++) {
            ans += nxt[i][0];
            ans %= MOD;
        }

        return ans;
    }
};