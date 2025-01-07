class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> st;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (words[i].find(words[j]) != string::npos)
                        st.insert(words[j]);
                }
            }
        }
        vector<string> ans;
        for (auto& str : st)
            ans.push_back(str);
        return ans;
    }
};