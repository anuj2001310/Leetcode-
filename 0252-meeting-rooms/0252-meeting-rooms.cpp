typedef vector<int> vi;
typedef vector<vi> vvi;
using pii = pair<int, int>;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals),
             [&](const auto& a, const auto& b) {
                 if (a[0] == b[0])
                     return b[1] > a[1];

                 return b[0] > a[0];
             });

        stack<pii> stk;
        for (int i = 0; i < n; ++i) {
            if (!stk.empty() && stk.top().second > intervals[i][0])
                return false;
            stk.push({intervals[i][0], intervals[i][1]});
        }
        return true;
    }
};