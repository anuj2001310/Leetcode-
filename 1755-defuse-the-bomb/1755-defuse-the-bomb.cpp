class Solution {
private:
    int forwardCircularSum(vector<int>& vec, int start, int cnt) {
        int sum = 0;
        int len = vec.size();
        for (int i = 0; i < cnt; i++)
            sum += vec[(start + i) % len];
        return sum;
    }

    int backwardCircularSum(vector<int>& vec, int start, int cnt) {
        int sum = 0;
        int len = vec.size();
        for (int i = 0; i < cnt; i++)
            sum += vec[(start - i - 1 + len) % len];
        return sum;
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size());

        if (k == 0)
            return res;

        else if (k > 0)
            for (int i = 0; i < code.size(); i++)
                res[i] = forwardCircularSum(code, i + 1, k);

        else
            for (int i = 0; i < code.size(); i++)
                res[i] = backwardCircularSum(code, i, abs(k));

        return res;
    }
};