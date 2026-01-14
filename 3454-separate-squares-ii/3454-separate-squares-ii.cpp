class Solution {
public:
    // function returns if upper part of y is greater than lower part
    bool helper(vector<array<long long, 4>>& v, int n, double y) {
        // if y is greater than y_end of last interval all squares lies below y
        // so false
        if (y >= v[n - 1][1]) {
            return false;
        }
        // if y is less than y_start of first interval all square lies above y
        // so true
        if (y <= v[0][0]) {
            return true;
        }

        double up = 0, down = 0;
        int l = 0, r = n - 1, idx = n;

        // finding where y lies using binary search, you can use full iteration
        // too maybe it'll pass dunno
        while (l <= r) {
            int m = (r + l) / 2;
            if (y < v[m][0]) {
                r = m - 1;
                idx = m;
            } else {
                l = m + 1;
            }
        }
        down = idx > 1 ? v[idx - 2][3] : 0;
        up = idx != n ? (v[n - 1][3] - v[idx - 1][3]) : 0;
        up -= down;
        down = 0;
        idx--;
        if (y >= v[idx][0] && y <= v[idx][1]) {
            up += (v[idx][1] - y) * v[idx][2];
            down += (y - v[idx][0]) * v[idx][2];
        } else {
            down += v[idx][3] - (idx != 0 ? v[idx - 1][3] : 0);
        }

        return up > down;
    }
    double separateSquares(vector<vector<int>>& squares) {
        map<int, vector<array<int, 3>>> mp;
        for (auto& a : squares) { // map y -> {x_start,x_end,is_y_start}
            mp[a[1]].push_back({a[0], a[0] + a[2], 1});
            mp[a[1] + a[2]].push_back({a[0], a[0] + a[2], 0});
        }

        vector<array<long long, 4>>
            v; //{y_start,y_end,x_val_sum_at_y_interval_non_overlapping,prefix_sum_of_areas}
        map<pair<int, int>, int> intervalMap;

        int prev_y = -1; // just initialize values with negative as they are out
                         // of bounds
        int prev_val = -1;

        for (auto& [y, intervals] :
             mp) { // for each y there are intervals of x starting or ending
            for (auto& interval : intervals) {
                if (interval[2]) { // if starting
                    intervalMap[{interval[0], interval[1]}]++;
                } else { // if ending
                    intervalMap[{interval[0], interval[1]}]--;
                    if (intervalMap[{interval[0], interval[1]}] == 0) {
                        intervalMap.erase({interval[0], interval[1]});
                    }
                }
            }

            int ptr1 = -1; // kept it such both pointers will be updated with
                           // first interval at first iteration
            int ptr2 = -1;
            int val =
                0; // this variable stores the sum of value of non-overlapping
                   // intervals at x-axis that starts at this y. Below loop is
                   // for that, it is important to use default comparator of map
                   // as this part of code is like merge intervals which
                   // requires sorted intervals
            for (auto& [interval, b] : intervalMap) {
                if (interval.first > ptr2) {
                    val += ptr2 - ptr1;
                    ptr1 = interval.first;
                    ptr2 = interval.second;
                } else {
                    ptr2 = max(ptr2, interval.second);
                }
            }
            // add last remaining interval
            val += ptr2 - ptr1;

            // from some y_start we have sum of intervals {x_start,x_end} as
            // prev_val till this y which becomes y_end, only add if prev_val is
            // non-zero
            if (prev_val > 0) {
                v.push_back(
                    {prev_y, y, prev_val, (1ll * y - prev_y) * prev_val});
                int tmp = v.size() - 1;
                if (tmp > 0) { // used prefix sum
                    v[tmp][3] += v[tmp - 1][3];
                }
            }
            // updating prev variables with current values
            prev_y = y;
            prev_val = val;
        }

        int n = v.size();

        double l = 0, r = 2e9;
        // binary search on answer, as this has decimal answer used fixed
        // iterations for it
        for (int k = 0; k < 100; ++k) {

            double m = (l + r) / 2.0;

            if (helper(v, n, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};