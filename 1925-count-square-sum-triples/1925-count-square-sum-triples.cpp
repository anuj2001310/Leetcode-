class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> set;
        for (int i = 1; i < n + 1; ++i) {
            set.insert(i * i);
        }

        int count = 0;
        for (int l = 1; l < n + 1; ++l) {
            for (int m = l + 1; m < n + 1; ++m) {
                if (set.find(l * l + m * m) != set.end())
                    count += 2;
            }
        }
        return count;
    }
};