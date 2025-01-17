class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int a = 0;
        for (auto& x : derived)
            a ^= x;
        return a == 0;
    }
};