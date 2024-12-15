class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            pq.push({((classes[i][0] + 1) / (double)(classes[i][1] + 1)) -
                         (classes[i][0] / (double)classes[i][1]),
                     i});
        }
        while (ex) {
            int i = pq.top().second;
            classes[i][0]++;
            classes[i][1]++;
            pq.pop();
            pq.push({((classes[i][0] + 1) / (double)(classes[i][1] + 1)) -
                         (classes[i][0] / (double)classes[i][1]),
                     i});
            ex--;
        }
        double a = 0;
        for (int i = 0; i < classes.size(); i++) {
            a += (classes[i][0] / (double)classes[i][1]);
        }
        return a / (double)classes.size();
    }
};