class Solution {
public:
    // discrete IVT over [a, b]
    struct elmt {
        int a, b;
    };

    int N = 1;
    vector<elmt> seg;
    vector<int> ops;

    void pow2(int n) {
        while (N < n)
            N <<= 1;
    }

    void propagate(int i, int w) {
        if (!w || !ops[i])
            return;
        int l = i << 1, r = l | 1;
        ops[l] += ops[i], ops[r] += ops[i];
        seg[l] = {seg[l].a + ops[i], seg[l].b + ops[i]};
        seg[r] = {seg[r].a + ops[i], seg[r].b + ops[i]};
        ops[i] = 0;
    }

    void update(int i, int l, int r, int nl, int nr, int val) {
        propagate(i, nr - nl);
        if (l <= nl && nr <= r) {
            seg[i] = {seg[i].a + val, seg[i].b + val};
            ops[i] += val;
            return;
        } else if (nl > r || nr < l)
            return;

        int m = (nl + nr) / 2, l_ = i << 1, r_ = l_ | 1;
        update(l_, l, r, nl, m, val);
        update(r_, l, r, m + 1, nr, val);

        seg[i] = {min(seg[l_].a, seg[r_].a), max(seg[l_].b, seg[r_].b)};
    }

    int query(int i) {
        propagate(i, i < N);
        if (i >= N)
            return !(seg[i].a && seg[i].b) ? i - N : N;
        int l = i << 1, r = l | 1;
        return query(seg[l].a <= 0 && seg[l].b >= 0 ? l : r);
    }

    int longestBalanced(vector<int>& a) {
        unordered_map<int, int> last;
        int n = a.size();
        pow2(n);
        seg.resize(2 * N);
        ops.resize(2 * N);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = last.count(a[i]) ? last[a[i]] : 0, r = i;
            update(1, l, r, 0, N - 1, (a[i] & 1) ? -1 : 1);
            ans = max(ans, i - query(1) + 1);
            last[a[i]] = i + 1;
        }
        return ans;
    }
};