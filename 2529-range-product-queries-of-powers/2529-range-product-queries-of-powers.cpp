class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> ans;
        vector<int> powers;
        int sum = 0;
        for (int i = 29; i >= 0; i--) {
            if (sum == n)
                break;

            if (sum + pow(2, i) <= n) {
                sum += pow(2, i);
                int power = pow(2, i);
                powers.push_back(power);
            }
        }

        reverse(powers.begin(), powers.end());

        for (int i = 0; i < queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];

            long long prod = 1;

            for (int k = s; k <= e; k++)
                prod = (prod * powers[k]) % mod;

            ans.push_back(prod);
        }
        return ans;
    }
};