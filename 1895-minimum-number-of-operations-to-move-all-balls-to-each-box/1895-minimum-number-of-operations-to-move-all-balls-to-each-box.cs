public class Solution {
    public int[] MinOperations(string boxes) {
        int n = boxes.Length;
        int b = 0, m = 0;
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            res[i] = (b + m);
            m += b;
            b += (boxes[i] - '0');
        }

        b = m = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += (b + m);
            m += b;
            b += (boxes[i] - '0');
        }
        return res;
    }
}