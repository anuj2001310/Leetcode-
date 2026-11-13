class Solution {
public:
    long long check(vector<int>& nums, int d) {
        double tot = 0;
        for (auto& num : nums)
            tot += ceil((double)(num) / d);
        return tot;
    }

    int minEatingSpeed(vector<int>& piles, int x) {
        int n = piles.size();
        int l = 1, h = *max_element(begin(piles), end(piles));
        while (l <= h) {
            int m = l + ((h - l) >> 1);
            double top = check(piles, m);
            if (top <= x)
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};