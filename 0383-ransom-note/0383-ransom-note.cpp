class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> fq(26, 0);
        for (auto& ch : magazine)
            fq[ch - 'a']++;
        
        for (auto& ch : ransomNote) {
            int id = ch - 'a';
            if (--fq[id] == -1)
                return false;
        }
        return true;
    }
};