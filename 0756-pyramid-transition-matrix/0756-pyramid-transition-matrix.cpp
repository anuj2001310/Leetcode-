class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(int idx, string& curr, string& next) {
        if (idx == curr.size() - 1) {
            if (memo.count(next))
                return memo[next];
            return memo[next] = canBuild(next);
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key))
            return false;

        for (char ch : mp[key]) {
            next.push_back(ch);
            if (dfs(idx + 1, curr, next))
                return true;
            next.pop_back();
        }
        return false;
    }

    bool canBuild(string curr) {
        if (curr.size() == 1)
            return true;

        string next;
        return dfs(0, curr, next);
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return canBuild(bottom);
    }
};