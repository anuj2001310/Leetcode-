class Solution {
private:
    struct cmp {
        bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            if (get<0>(a) == get<0>(b))
                return get<1>(b) > get<1>(a);
            return get<0>(a) > get<0>(b);
        }
    };

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                int sum = i + j;
                pq.push(make_tuple(sum, i, j));
            }
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            auto t = pq.top();
            auto r = get<1>(t);
            auto c = get<2>(t);
            pq.pop();

            ans.push_back(nums[r][c]);
        }

        return ans;
    }
};