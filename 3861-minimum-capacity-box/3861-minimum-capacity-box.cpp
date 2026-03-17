class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = size(capacity);
        int ans = -1;
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (capacity[i] >= itemSize && capacity[i] < min)
                ans = i, min = capacity[i];
        }
        return ans;
    }
};