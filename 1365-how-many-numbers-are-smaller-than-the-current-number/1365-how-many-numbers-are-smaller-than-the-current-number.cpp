class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int c[102] = {};
        for (auto& i : a)
            c[i]++;
        for (int i = 1; i < 101; i++)
            c[i] += c[i - 1];
        for (auto& i : a)
            i = c[(i - 1) == -1 ? 101 : (i - 1)];
        return a;
    }
};