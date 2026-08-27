class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int mindis = std::numeric_limits<int>::max();
        for (int i = 0; i < drones.size(); i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int dis = fabs(x - target[0]) + fabs(y - target[1]);
            if (dis <= range && dis < mindis) {
                mindis = dis;
                ans = i;
            }
        }

        return ans;
    }
};