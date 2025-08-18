#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        // Convert to doubles to perform division and floating comparisons
        // safely.
        vector<double> nums(cards.begin(), cards.end());
        // Kick off backtracking search with a small epsilon for float equality.
        const double EPS = 1e-6;
        return dfs(nums, EPS);
    }

private:
    // Try all ways to combine numbers to reach 24 (within EPS tolerance).
    bool dfs(vector<double>& nums, const double EPS) {
        // Base case: when only one number is left, check if it's
        // approximately 24.
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        // Choose an unordered pair (i, j), i < j, to combine next.
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Build the list of remaining numbers after removing i and j.
                vector<double> rest;
                rest.reserve(
                    n -
                    1); // we will push back one result later → size becomes n-1
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        rest.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // All possible results using a and b.
                // For non-commutative ops (- and /), consider both a∘b and b∘a.
                vector<double> cand;
                cand.reserve(6);
                cand.push_back(a + b);
                cand.push_back(a * b);
                cand.push_back(a - b);
                cand.push_back(b - a);
                if (fabs(b) > EPS)
                    cand.push_back(a / b);
                if (fabs(a) > EPS)
                    cand.push_back(b / a);

                // Try each candidate result; recurse with reduced list.
                for (double x : cand) {
                    rest.push_back(x);
                    if (dfs(rest, EPS))
                        return true; // Found a valid way to make 24.
                    rest.pop_back(); // Backtrack and try next operation.
                }
            }
        }
        // Exhausted all possibilities without success.
        return false;
    }
};