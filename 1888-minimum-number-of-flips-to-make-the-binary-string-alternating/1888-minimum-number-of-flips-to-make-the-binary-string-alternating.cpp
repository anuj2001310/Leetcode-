class Solution {
public:
    int helper(int n, int onesInEvenPlace, int onesInOddPlace) {
        if (onesInEvenPlace < 0 || onesInOddPlace < 0) {
            return INT_MAX;
        }
        return min((n + 1) / 2 - onesInEvenPlace + onesInOddPlace,
                   (n / 2) - onesInOddPlace + onesInEvenPlace);
    }
    int minFlips(string s) {
        int onesInOddPlace = 0;
        int onesInEvenPlace = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i & 1) == 0 && s[i] == '1') {
                onesInEvenPlace++;
            }
            if (i % 2 == 1 && s[i] == '1') {
                onesInOddPlace++;
            }
        }
        int n = s.size();
        int ans = helper(n, onesInEvenPlace, onesInOddPlace);
        if (n & 1) {
            for (int i = 1; i < n; i++) {
                int temp = onesInEvenPlace;
                onesInEvenPlace = onesInOddPlace;
                onesInOddPlace = temp;
                if (s[i - 1] == '1') {
                    if (onesInOddPlace != 0) {
                        onesInOddPlace--;
                        onesInEvenPlace++;
                    }
                }
                ans = min(ans, helper(n, onesInEvenPlace, onesInOddPlace));
            }
        }
        return ans;
    }
};