class Solution {
public:
    bool largestSeq(vector<int>& a, int n = 0, int ind = 0, int mask = 0) {
        int s = a.size();
        if (mask == (1 << n) - 1)
            return true;

        if (a[ind] != 0)
            return largestSeq(a, n, ind + 1, mask);

        for (int i = n; i >= 1; i--) {
            if (!(mask & 1 << (i - 1))) {
                if (i == 1) {
                    a[ind] = i;

                    if (largestSeq(a, n, ind + 1, mask | 1 << (i - 1)))
                        return true;

                    a[ind] = 0;
                }

                else if ((ind + i < s) && a[ind + i] == 0) {
                    a[ind] = i;
                    a[ind + i] = i;

                    if (largestSeq(a, n, ind + 1, mask | 1 << (i - 1)))
                        return true;

                    a[ind] = 0;
                    a[ind + i] = 0;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * (n - 1) + 1, 0);
        largestSeq(ans, n);
        return ans;
    }
};