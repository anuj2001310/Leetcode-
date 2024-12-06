class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> hash(10001, false);
        for (auto& i : banned)
            hash[i] = true;

        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!hash[i]) {
                sum += i;
                if (sum <= maxSum)
                    count++;
                else
                    return count;
            } else
                continue;
        }

        return count;
    }
};