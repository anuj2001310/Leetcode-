class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        boolean[] pa = new boolean[n + 1];  
        boolean[] pb = new boolean[n + 1];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += A[i] == B[i] ? 1 : 0;
            cnt += pa[B[i]] ? 1 : 0;
            cnt += pb[A[i]] ? 1 : 0;

            pa[A[i]] = true;
            pb[B[i]] = true;
            ans[i] = cnt;
        }
        return ans;
    }
}