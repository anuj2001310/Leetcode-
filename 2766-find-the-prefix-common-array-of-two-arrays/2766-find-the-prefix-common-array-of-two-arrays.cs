public class Solution {
    public int[] FindThePrefixCommonArray(int[] A, int[] B) {
        int n = A.Length;
        var ans = new int[n];
        
	    var presentA = new bool[n + 1];
	    var presentB = new bool [n + 1];
	    var cnt = 0;
	    for (var i = 0; i < n; i++) {
		    cnt += A[i] == B[i] ? 1 : 0;
		    cnt += presentA[B[i]] ? 1 : 0;
		    cnt += presentB[A[i]] ? 1 : 0;
		    presentA[A[i]] = true;
		    presentB[B[i]] = true;
		    ans[i] = cnt;
	    }
	    return ans;
    }
}