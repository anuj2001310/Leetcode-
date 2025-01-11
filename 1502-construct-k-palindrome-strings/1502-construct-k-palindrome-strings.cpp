class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k)
            return false;
        
        vector<int> maps(26, 0);
        for (uint i = 0; i < n; i++)
            maps[s[i] - 'a']++;
        
        int cnt = 0;
        for (uint i = 0; i < 26; i++) {
            if (maps[i] & 1)
                cnt++;
        }
        if (cnt > k)
            return false;

        return true;
    }
};