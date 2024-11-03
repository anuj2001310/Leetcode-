class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() > goal.length())
            return false;
        string c = s + s;
        if (c.find(goal) != string::npos)
            return true;
        return false;
    }
};