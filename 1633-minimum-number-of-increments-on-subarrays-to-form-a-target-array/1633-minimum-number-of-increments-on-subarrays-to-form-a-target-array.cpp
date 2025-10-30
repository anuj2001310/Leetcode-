class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0;
        int rez = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] > prev)
                rez += target[i] - prev;
            prev = target[i];
        }

        return rez;
    }
};