class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long total = 0;
        for (auto& x : chalk)
            total += x;
        k %= total; // This will eventually done complete round part
        // The only work remaining now is to find where gonna i -> pointer be stopped.
        for (int i = 0; i < n; ++i) {
            if (chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return -1;
    }
};