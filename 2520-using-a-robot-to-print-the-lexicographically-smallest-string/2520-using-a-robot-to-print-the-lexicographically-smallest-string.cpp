char t[100000], xMin[100000];
int top = -1;
class Solution {
public:
    static string robotWithString(string& s) {
        int freq[26] = {0}, n = s.size();
        xMin[n - 1] = s.back();
        for (int i = n - 2; i >= 0; i--) // suffix min
            xMin[i] = min(s[i], xMin[i + 1]);

        string p;
        top = -1; // reset for t
        p.reserve(n);
        for (int i = 0; i < n; i++) {
            t[++top] = s[i];
            while (top != -1 && (i == n - 1 || t[top] <= xMin[i + 1])) {
                p += t[top--];
            }
        }
        return p;
    }
};