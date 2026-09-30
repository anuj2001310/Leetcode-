typedef vector<int> vi;
using pii = pair<int, int>;
class Solution {
public:
    vi maxDepthAfterSplit(string s) {
        int n = s.size();
        vi res(n);

        for (int i = 0; i < n; i++)
            res[i] = (i ^ s[i]) & 1;

        return res;
    }
};