class Solution {
  List<int> findThePrefixCommonArray(List<int> A, List<int> B) {
    int n = A.length;
    List<int> ans = List.filled(n, 0);
    List<bool> presentA = List.filled(n + 1, false);
    List<bool> presentB = List.filled(n + 1, false);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      if (A[i] == B[i]) {
        cnt++;
      }
      if (presentA[B[i]]) {
        cnt++;
      }
      if (presentB[A[i]]) {
        cnt++;
      }
      presentA[A[i]] = true;
      presentB[B[i]] = true;
      ans[i] = cnt;
    }

    return ans;
  }
}