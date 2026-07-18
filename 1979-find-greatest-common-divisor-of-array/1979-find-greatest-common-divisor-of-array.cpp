class Solution {
public:
    int findGCD(vector<int>& nums) {

        int Min = INT_MAX;
        int Max = INT_MIN;
        for (auto& x : nums) {
            Min = min(Min, x);
            Max = max(Max, x);
        }
        while (Min != Max) {
            if (Max > Min)
                Max -= Min;
            else
                Min -= Max;
        }
        return Max;
    }
};
static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();