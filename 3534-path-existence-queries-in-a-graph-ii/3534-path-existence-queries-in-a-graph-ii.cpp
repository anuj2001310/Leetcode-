typedef pair<int, int> pii;
typedef vector<int> vi;
using vvi = vector<vi>;

#define Rep(a, b, c, d) for (int a = b; a < c; a += d)

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vi& nums, int maxDiff,
        vvi& queries) {
            
        int LOG = 18;

        vector<pii> vec;
        Rep(i, 0, n, 1) vec.push_back({nums[i], i});

        sort(vec.begin(), vec.end());

        vi getSortIdx(n);
        Rep(i, 0, n, 1) getSortIdx[vec[i].second] = i;

        vvi st(n, vector<int>(LOG, 0));
        int l = 0;

        Rep(r, 0, n, 1) {
            while (vec[r].first - vec[l].first > maxDiff) {
                st[l][0] = r - 1;
                l++;
            }
        }

        while (l < n) {
            st[l][0] = n - 1;
            l++;
        }

        Rep(j, 1, LOG, 1) {
            Rep(i, 0, n, 1) st[i][j] = st[st[i][j - 1]][j - 1];
        }

        int m = queries.size();

        vi ans(m, -1);

        Rep(i, 0, m, 1) {
            int a = getSortIdx[queries[i][0]];
            int b = getSortIdx[queries[i][1]];

            if (a > b)
                swap(a, b);

            if (a == b) {
                ans[i] = 0;
                continue;
            }

            int cur = a;
            int step = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (st[cur][j] < b) {
                    step += 1 << j;
                    cur = st[cur][j];
                }
            }

            if (st[cur][0] >= b)
                ans[i] = step + 1;
            
        }

        return ans;
    }
};