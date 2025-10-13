class Solution {
private:
    bool isAna(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> fre(26, false);

        for (int i = 0; i < s.length(); i++) {
            fre[s[i] - 'a']++;
            fre[t[i] - 'a']--;
        }
        for (int i = 0; i < fre.size(); i++) {
            if (fre[i] != 0)
                return false;
        }
        return true;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < n; ++i) {
            if (isAna(words[i], words[i - 1]))
                continue;

            ans.push_back(words[i]);
        }
        /*
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            ans.push_back(top);
        }*/
        return ans;
    }
};