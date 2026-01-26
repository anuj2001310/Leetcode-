#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
 
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            m = min(m,diff);  
        }
        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (m == diff) 
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};