class Solution {
private:
    int divideConcour(string& s, int l, int r) {
        int n = r - l + 1;

        if (n == 2)
            return 1;

        int score = 0;
        int split_idx = -1;

        int opening = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '(')
                opening++;
            else if (opening > 0)
                opening--;

            if (opening == 0) {
                split_idx = i;
                break;
            };
        }

        if (split_idx == r)
            return 2 * divideConcour(s, l + 1, r - 1);

        return divideConcour(s, l, split_idx) + divideConcour(s, split_idx + 1, r);
    }

public:
    int scoreOfParentheses(string s) {
        return divideConcour(s, 0, s.size() - 1);
    }
};