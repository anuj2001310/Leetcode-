class Solution {
public:
    string clearDigits(string s) {
        stack<char> stack;
        for (auto& ch : s) {
            if (ch >= '0' and ch <= '9' and !stack.empty())
                stack.pop();
            else
                stack.push(ch);
        }
        string t = "";
        while(!stack.empty()){
            t = stack.top() + t;
            stack.pop();
        }
        return t;
    }
};