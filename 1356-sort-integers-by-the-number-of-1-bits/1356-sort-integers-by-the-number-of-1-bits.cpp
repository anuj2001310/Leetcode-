using pii = pair<int, int>;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = size(arr);
        vector<pii> vec;
        for (int i = 0; i < n; ++i) {
            int b = __builtin_popcount(arr[i]);
            vec.push_back({b, arr[i]});
        }
        //{bits, val}
        sort(begin(vec), end(vec), [&](const pii& a, const pii& b) {
            if (a.first == b.first)
                return a.second < b.second;
            
            return a.first < b.first;
        });
        for (int i = 0; i < n; i++) 
            arr[i] = vec[i].second;
        
        return arr;
    }
};