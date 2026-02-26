class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
        stack<int> stk;

        for (auto& digit : s)
            stk.push(digit - '0');

        while (stk.size() != 1) {
            int curr = stk.top();
            stk.pop();

            if (curr == 0 and carry == 0)
                res += 1;

            else if (curr == 1 and carry == 0) {
                carry = 1;
                res += 2;
            }

            else if (curr == 0 and carry)
                res += 2;

            else
                res += 1;
        }

        if (stk.top() == 1 and carry)
            res += 1;

        return res;
    }
};