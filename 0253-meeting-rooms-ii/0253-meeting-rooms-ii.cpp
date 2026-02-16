typedef vector<int> vi;
typedef vector<vi> vvi;
using pii = pair<int, int>;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b) {
            if (a[0] < b[0])
                return true;
            else if (a[0] > b[0])
                return false;
            else
                return a[1] < b[1];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int roomId = 1;
        // {meeting endTime, roomId}
        pq.push({intervals[0][1], roomId});
        for (int i = 1; i < n; i++) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            pair<int, int> tp = pq.top();
            if (tp.first <= startTime) {
                tp.first = endTime;
                pq.pop();
                pq.push(tp);
            } else {
                roomId++;
                pq.push({endTime, roomId});
            }
        }
        return pq.size();
    }
};