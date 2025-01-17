class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for (auto& fuck : derived)
            ans ^= fuck;
        return ans == 0;
    }
};