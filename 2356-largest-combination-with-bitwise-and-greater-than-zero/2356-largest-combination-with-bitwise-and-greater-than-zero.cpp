class Solution {
private:
    void countBits(int num, vector<int>& freq) {
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if (mask & num)
                freq[i]++;
        }
    }

public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(32, 0);
        for (int i = 0; i < candidates.size(); ++i)
            countBits(candidates[i], freq);

        int ans = 0;
        for (int x : freq)
            ans = fmax(ans, x);
        return ans;
    }
};