class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.length();
        string h = "!?',;.";
        string res = "";
        vector<string> temp;
        for (int i = 0; i < n; ++i) {
            if ((paragraph[i] == ' ') || (h.find(paragraph[i]) != string::npos)) {
                temp.push_back(res);
                res = "";
            } else
                res += paragraph[i];
        }
        if (!res.empty())
            temp.push_back(res);
        unordered_map<string, int> map;
        unordered_set<string> vis(begin(banned), end(banned));
        // for (auto it : vis)
        //     cout << it << " -> ";
        // cout << endl;
        for (auto& t : temp) {
            // while (!t.empty() && h.find(t.back()) != string::npos)
            //     t.pop_back();
            // while (!t.empty() && h.find(t.front()) != string::npos)
            //     t.erase(t.begin());
            for (auto& ch : t)
                ch = tolower(ch);
            if (vis.count(t) || t.empty())
                continue;
            map[t]++;
        }

        int f = -1;
        string ans = "";
        for (auto& [k, v] : map) {
            // cout << k << "-" << v << endl;
            if (v > f) {
                f = v;
                ans = k;
            }
        }
        return ans;
    }
};
