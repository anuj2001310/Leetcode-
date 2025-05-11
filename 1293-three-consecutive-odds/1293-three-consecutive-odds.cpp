class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (arr[i] & 1)
                cnt++;
            else
                cnt = 0;
            if ((cnt & 1) and ((1 << 1) & cnt))
                return true;
        }
        return false;
    }
};