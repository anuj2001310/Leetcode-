class Solution {
public:
    int countOperations(int n1, int n2) {
        int ct = 0;
        while (n1 != 0 && n2 != 0) {
            ++ct;
            if (n1 > n2)
                n1 -= n2;
            else if (n2 >= n1)
                n2 -= n1;
        }
        return ct;
    }
};