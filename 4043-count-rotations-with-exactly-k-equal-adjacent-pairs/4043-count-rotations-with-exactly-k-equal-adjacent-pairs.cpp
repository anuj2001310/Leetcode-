class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
                total++;
        

        if (s[0] == s[n - 1])
            total++;

        return k == total ? n - total : (k == total - 1 ? total : 0);
    }
};