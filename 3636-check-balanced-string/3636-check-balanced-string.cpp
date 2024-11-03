class Solution {
public:
    bool isBalanced(string num) {
        int even = 0, odd = 0;
        for (int i = 0; i < num.length(); ++i) {
            int sum = num[i] - '0';
            if (i & 1)
                even += sum;
            else
                odd += sum;
        }
        return even == odd;
    }
};