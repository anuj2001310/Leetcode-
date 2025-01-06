class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        int b = 0, m = 0;
        vector<int> res(n, 0);

        for (uint i = 0; i < n; i++) {
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
};