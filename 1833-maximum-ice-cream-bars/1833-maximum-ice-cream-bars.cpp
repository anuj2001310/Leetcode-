class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = size(costs);
        int ct = 0;
        sort(begin(costs), end(costs));

        for (int i = 0; i < n; i++) {
            if (coins - costs[i] < 0)
                break;
            coins -= costs[i];
            ct++;

        }
        return ct;
    }
};