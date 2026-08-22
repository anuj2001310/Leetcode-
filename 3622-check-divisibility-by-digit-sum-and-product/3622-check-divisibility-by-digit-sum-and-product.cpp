class Solution {
private:
    pair<int, int> dig(int num) {
        if (num == 0)
            return {0, 1};

        int r = num % 10;

        auto p = dig(num / 10);

        return {p.first + r, p.second * r};
    }

public:
    bool checkDivisibility(int n) {
        return n % (dig(n).first + dig(n).second) == 0;
    }
};