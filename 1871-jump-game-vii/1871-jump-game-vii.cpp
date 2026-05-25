class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        // dp[i] = true -> we can reach the ith index by jumping under the constraints 
        // dp[i] = false -> means we can not reach the i th index by jumping under the given constraints
        dp[0] = true;
        // this dq will store all the indices from where we can jump at the current index i and also dp[indices in dq] == true 
        // this is because the indices in dq must also be reachable themselves also
        deque<int> dq;
        int j = 0; 

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') continue;
            // if s[i] was one then their is no scope of reaching i th index
            while (j <= i - minJump) {
                if (dp[j]) dq.push_back(j);
                j++;
            }
            // keep only those indices which are in the given possible range
            while (!dq.empty() && dq.front() < i - maxJump) {
                dq.pop_front();
            }
            // if any index is present withnin the given range then the current position is reachable 
            // else we can not reach the current position
            if (!dq.empty()) {
                dp[i] = true;
            }
        }
        // return the possiblily of reaching the n - 1 th index
        return dp[n - 1];
    }
};