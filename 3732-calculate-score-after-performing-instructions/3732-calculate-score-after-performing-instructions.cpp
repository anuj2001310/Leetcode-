class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        vector<bool> vis(n, false);

        long long sum = 0;
        for (int i = 0; i < n and i >= 0; ) {
            if (vis[i])
                break;
            
            vis[i] = true;
            
            if (instructions[i] == "add") {
                    sum += values[i];
                    i++;
                }
            else 
                i += values[i];
        }
        return sum;
    }
};