class Solution {
    using ll = long long;
    using pll = pair<ll, ll>;
    using vpll = vector<pll>;

public:
    int mostBooked(int n1, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        ll n = meetings.size();
        priority_queue<pll, vpll, greater<pll>> pq;
        priority_queue<ll, vector<ll>, greater<ll>> pq1;
        for (ll i = 0; i < n1; i++)
            pq1.push(i);
        vector<ll> cnt(n, 0);
        for (ll i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= meetings[i][0]) {
                auto x = pq.top();
                pq.pop();
                pq1.push(x.second);
            }
            if (!pq1.empty()) {
                auto a = pq1.top();
                pq1.pop();
                cnt[a]++;
                pq.push({meetings[i][1], a});
            } else {
                auto b = pq.top();
                pq.pop();
                auto start = b.first;
                auto room = b.second;

                cnt[room]++;
                pq.push({start + meetings[i][1] - meetings[i][0], room});
            }
        }

        int k = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        return k;
    }
};