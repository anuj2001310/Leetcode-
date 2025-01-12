class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n & 1)
            return false;

        stack<int> open;
        stack<int> close;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                close.push(i);
            else if (s[i] == '(')
                open.push(i);
            else if (s[i] == ')')
                if (!open.empty())
                    open.pop();
                else if (!close.empty())
                    close.pop();
                else
                    return false;
        }
        while (!open.empty() and !close.empty() and open.top() < close.top()) {
            open.pop();
            close.pop();
        }

        return open.empty();
    }
};