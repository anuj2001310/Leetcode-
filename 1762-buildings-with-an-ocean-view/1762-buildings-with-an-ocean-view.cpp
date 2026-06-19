#define inf std::numeric_limits<int>::max()
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans;
        int max = -inf;
        for (int i = n - 1; i >= 0; i--) {
            if (heights[i] > max)
                ans.push_back(i);
            
            max = fmax(max, heights[i]);

        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};