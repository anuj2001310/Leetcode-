class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int maxIndex = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < gifts.size(); j++) {
                if (gifts[j] > gifts[maxIndex]) {
                    maxIndex = j;
                }
            }
            gifts[maxIndex] = (int)floor(sqrt(gifts[maxIndex]));
            maxIndex = 0;

        }

        long long sum = 0;
        for (int i = 0; i < gifts.size(); i++)
            sum += gifts[i];

        return sum;
    }
};