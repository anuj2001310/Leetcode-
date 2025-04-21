class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0, min = 0, max = 0;
        for (auto& d : differences) {
            curr += d;
            min = (min < curr) ? min : curr;
            max = (max > curr) ? max : curr;

            if ((upper - max) - (lower - min) + 1 <= 0)
                return 0;
        }
        return upper - max - lower + min + 1;
    }
};