class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> vis (n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (baskets[j] >= fruits[i] and !vis[j]) {
                    vis[j] = true;
                    break;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += (vis[i] ? 0 : 1);
    
        return cnt;
    }
};