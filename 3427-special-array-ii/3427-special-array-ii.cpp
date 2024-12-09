class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        unsigned l = nums.size();
        unsigned alts[l];
        alts[0] = 0;
        unsigned i;
        for (i = 1; i < l; i++) {
            alts[i] = (nums[i] ^ nums[i - 1]) & 1 ? alts[i - 1] : i;
        }
        vector<bool> result(queries.size());
        for (i = 0; i < queries.size(); i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            result[i] = alts[to] <= from;
        }
        return result;
    }
};