class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        multiset<int> gapsize;
        vector<pair<int, int>> v;
        for (int i = 0; i < startTime.size(); i++) {
            v.push_back({startTime[i], endTime[i]});
        }
        sort(v.begin(), v.end());
        gapsize.insert(v[0].first - 0);
        int n = v.size();
        gapsize.insert(eventTime - v[n - 1].second);
        int ans = 0;
        for (int i = 1; i < v.size(); i++) {
            gapsize.insert(v[i].first - v[i - 1].second);
        }
        for (int i = 0; i < v.size(); i++) {
            int leftgap = (i == 0) ? v[i].first : v[i].first - v[i - 1].second;
            int rightgap = (i == n - 1) ? eventTime - v[i].second
                                        : v[i + 1].first - v[i].second;
            int duration = v[i].second - v[i].first;

            gapsize.erase(gapsize.find(leftgap));
            gapsize.erase(gapsize.find(rightgap));

            if (!gapsize.empty() && *gapsize.rbegin() >= duration) {
                ans = max(ans, duration + leftgap + rightgap);
            }

            ans = max(ans, rightgap + leftgap);

            gapsize.insert(leftgap);
            gapsize.insert(rightgap);
        }

        return ans;
    }
};