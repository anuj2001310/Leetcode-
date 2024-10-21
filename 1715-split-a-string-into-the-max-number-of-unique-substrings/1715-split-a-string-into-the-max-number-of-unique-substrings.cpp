class Solution {
private:
    bool splitsUnique(string s, int splits, unordered_set<string>& m) {
        if (s.length() < splits)
            return false;
        if (s.empty() && splits == 0)
            return true;

        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if (m.find(sub) != m.end())
                continue;

            m.insert(sub);

            if (splitsUnique(s.substr(i), splits - 1, m))
                return true;
            m.erase(sub);
        }

        return false;
    }

public:
    int maxUniqueSplit(string s) {
        for (int i = s.length(); i > 1; i--) {
            unordered_set<string> m;
            if (splitsUnique(s, i, m))
                return i;
        }
        return 1;
    }
};