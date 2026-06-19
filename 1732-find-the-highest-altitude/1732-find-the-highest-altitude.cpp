class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0, curr = 0;
        auto it = gain.begin();
        for (; it != gain.end(); it++) {
            curr += *it;
            max = fmax(max, curr);
        }
        return max;
    }
};