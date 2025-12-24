class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int n = size(apple);
        int m = size(cap);
        int v = 0, x = accumulate(begin(apple), end(apple), 0);
        sort(rbegin(cap), rend(cap));
        //for(auto& c : cap) cout<<c<<" ";
        for (int i = 0; i < m; i++) {
            v += cap[i];
            if (v >= x)
                return i + 1;
        }
        return -1;
    }
};