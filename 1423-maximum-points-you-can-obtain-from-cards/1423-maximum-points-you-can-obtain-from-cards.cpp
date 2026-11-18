class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int rsum = 0, mxSum = lsum, rdx = n - 1;

        for (int i = k - 1; i >= 0; --i) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rdx--];
            mxSum = fmax(mxSum, lsum + rsum);
        }
        return mxSum;
    }
};