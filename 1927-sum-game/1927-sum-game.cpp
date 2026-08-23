using pii = pair<int, int>;
using vi = vector<int>;
class Solution {
public:
    bool sumGame(string str) {
        int n = str.length();

        auto solve = [&](string&& s) -> pii {
            int nn = 0, qq = 0;
            for (auto& ch : s) {
                if (ch == '?')
                    ++qq;
                else
                    nn += (ch - '0');
            }

            return {nn, qq};
        };

        auto [n0, q0] = solve(str.substr(0, n / 2));
        auto [n1, q1] = solve(str.substr(n / 2, n / 2));

        return ((q0 + q1) & 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
    }
};