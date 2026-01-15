class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int max_len1 = 1;
        int max_len2 = 1;

        int len1 = 1;
        int len2 = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i - 1] + 1 == hBars[i])
                len1++;
            else
                len1 = 1;

            max_len1 = max(max_len1, len1);
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i - 1] + 1 == vBars[i])
                len2++;
            else
                len2 = 1;

            max_len2 = max(max_len2, len2);
        }

        int len = min(max_len1, max_len2);
        return pow((len + 1), 2);
    }
};