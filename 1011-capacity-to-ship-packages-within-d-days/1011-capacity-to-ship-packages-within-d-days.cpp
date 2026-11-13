class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 0;
        int n = weights.size();
        for (int i = 0; i < n; ++i) {
            l = fmax(l, weights[i]);
            h += weights[i];
        }
        auto findDays = [&](const vector<int>& weights, int cap, int n) -> int {
            int d = 1, load = 0;
            for (int i = 0; i < n; ++i) {
                if (weights[i] + load > cap) {
                    d++;
                    load = weights[i];
                } else
                    load += weights[i];
            }
            return d;
        };

        while (l <= h) {
            int m = l + ((h - l) >> 1);
            int noDays = findDays(weights, m, n);
            if (noDays <= days)
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};