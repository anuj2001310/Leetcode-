class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> presentA(n + 1, false);
        vector<bool> presentB(n + 1, false);
        vector<int> ans(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += presentB[A[i]];
            cnt += presentA[B[i]];
            cnt += A[i] == B[i];
            presentA[A[i]] = true;
            presentB[B[i]] = true;
            ans[i] = cnt;
        }
        return ans;
    }
};