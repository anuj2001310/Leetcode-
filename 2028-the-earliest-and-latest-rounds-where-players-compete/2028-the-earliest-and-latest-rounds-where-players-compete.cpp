class Solution {
public:
    vector<int> earliestAndLatest(int n, int fp, int sp) {
        int left = min(fp, sp);
        int right = max(fp, sp);

        if (fp + sp == n + 1)
            return {1, 1};
        if (n <= 4)
            return {2, 2};

        if (left - 1 > n - right) {
            int tmp = n + 1 - left;
            left = n + 1 - right;
            right = tmp;
        }

        int mini = n, maxi = 1;
        int next = (n + 1) / 2;

        if (right * 2 <= n + 1) {
            int pre = left - 1;
            int mid = right - left - 1;
            for (int i = 0; i <= pre; i++) {
                for (int j = 0; j <= mid; j++) {
                    vector<int> it = earliestAndLatest(next, i + 1, i + j + 2);
                    mini = min(mini, 1 + it[0]);
                    maxi = max(maxi, 1 + it[1]);
                }
            }
        } else {
            int mirror = n + 1 - right;
            int pre = left - 1;
            int mid = mirror - left - 1;
            int btw = right - mirror - 1;
            for (int i = 0; i <= pre; i++) {
                for (int j = 0; j <= mid; j++) {
                    int pos1 = i + 1;
                    int pos2 = i + j + 1 + (btw + 1) / 2 + 1;
                    vector<int> it = earliestAndLatest(next, pos1, pos2);
                    mini = min(mini, 1 + it[0]);
                    maxi = max(maxi, 1 + it[1]);
                }
            }
        }
        return {mini, maxi};
    }
};