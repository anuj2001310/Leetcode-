class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e5 + 1;

        while (l < r) {
            int mid = (l + r) / 2, sum = 0;
            for (int& q : quantities) {
                sum += q / mid;
                sum += (q % mid != 0) ? 1 : 0;
            }

            if (sum > n)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};