class Solution {
private:
    bool helper(int f[], int mf[]) {
        for (uint i = 0; i < 26; i++) {
            if (f[i] < mf[i])
                return false;
        }
        return true;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int mf[26] = {};
        for (auto& word : words2) {
            int f[26] = {};
            for (auto& s : word)
                f[s - 'a']++;
            
            for (int i = 0; i < 26; ++i)
                mf[i] = fmax(mf[i], f[i]);
            
        }
        for (auto& word : words1) {
            int f[26] = {};
            for (auto& s : word)
                f[s - 'a']++;
            if (helper(f, mf))
                ans.push_back(word);
        }
        return ans;
    }
};