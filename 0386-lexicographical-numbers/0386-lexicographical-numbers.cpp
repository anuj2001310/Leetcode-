class Solution {
public:
    vector<int> ans;

    void chk(int cur, int n) {
        if (cur * 10 > n)
            return;

        for (int i = cur * 10; i < cur * 10 + 10 && i <= n; i++) {
            ans.push_back(i);
            chk(i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9 && i <= n; i++) {
            ans.push_back(i);
            chk(i, n);
        }

        return ans;
    }
};