class Solution {
    using pii = pair<int, int>;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for (int i = 0; i < n; ++i) {
            int num = fabs(arr[i] - x);
            pq.push ({num, arr[i]});
        }
        
        vector<int> ans;
        while (k-- and !pq.empty()) {
            auto val = pq.top().second;
            pq.pop();
            ans.push_back(val);
        }
        sort(ans.begin(), ans.end());
        
             
          return ans;      
    }
};