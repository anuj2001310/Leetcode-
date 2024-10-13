class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        int maxi = -1e9;
        int temp = 1e9;
        pair<int, int> p;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
        }
        while (!pq.empty()) {
            int mini = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (temp > (maxi - mini)) {
                p = {mini, maxi};
                temp = maxi - mini;
            }
            if (col + 1 < nums[row].size()) {
                pq.push({nums[row][col + 1], {row, col + 1}});
                maxi = fmax(maxi, nums[row][col + 1]);
            } 
            else
                break;
        }
        return {p.first, p.second};
    }
};