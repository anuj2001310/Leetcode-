class Solution {
    vector<int> segTree;
    
    void buildSegTree(vector<int>& heights, int s, int e, int s_idx) {
        if (s == e) {
            segTree[s_idx] = s;
            return;
        }
        int m = s + ((e - s) >> 1);
        buildSegTree(heights, s, m, 2 * s_idx);
        buildSegTree(heights, m + 1, e, 2 * s_idx + 1);
        segTree[s_idx] =
            heights[segTree[2 * s_idx]] >= heights[segTree[2 * s_idx + 1]]
                ? segTree[2 * s_idx]
                : segTree[2 * s_idx + 1];
    }

    int rangeQuery(vector<int>& heights, int qs, int qe, int s, int e,
                   int s_idx = 1) {
        if (s >= qs and e <= qe)
            return segTree[s_idx];

        if (s > qe or e < qs)
            return INT_MIN;
        int m = s + ((e - s) >> 1);
        int left = rangeQuery(heights, qs, qe, s, m, 2 * s_idx);
        int right = rangeQuery(heights, qs, qe, m + 1, e, 2 * s_idx + 1);
        if (left == INT_MIN)
            return right;
        if (right == INT_MIN)
            return left;
        return heights[left] >= heights[right] ? left : right;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree = vector<int>(4 * n + 1);
        int s_idx = 1;
        buildSegTree(heights, 0, n - 1, s_idx);
        vector<int> res;
        for (auto& q : queries) {
            auto alice = fmin(q[0], q[1]);
            auto bob = fmax(q[0], q[1]);
            if (alice == bob or heights[bob] > heights[alice]) {
                res.push_back(bob);
                continue;
            }

            int l = bob;
            int h = n - 1;
            int ans = INT_MAX;
            while (l <= h) {
                int m = l + ((h - l) >> 1);
                int r = rangeQuery(heights, l, m, 0, n - 1, s_idx);
                if (heights[r] > heights[alice]) {
                    h = m - 1;
                    ans = fmin(ans, r);
                } else
                    l = m + 1;
            }
            if (ans == INT_MAX)
                res.push_back(-1);
            else
                res.push_back(ans);
        }
        return res;
    }
};