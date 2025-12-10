class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long cnt = 1;
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] < complexity[0])
                return 0;
            if (complexity[i] == complexity[0])
                return 0;
            cnt = (cnt * i) % 1000000007;
        }
        return cnt;
    }
};