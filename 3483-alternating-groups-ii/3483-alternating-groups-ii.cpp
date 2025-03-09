class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int maxAlter = 0, count = 1, n = colors.size();

        for (int i = 0; i < k - 1; i++) {
            if (colors[i] != colors[i + 1])
                count++;
        }

        if (count == k)
            maxAlter++;

        for (int i = k; i < k - 1 + n; i++) {
            if (colors[(i - k + 1) % n] != colors[(i - k) % n])
                count--;

            if (colors[i % n] != colors[(i - 1) % n])
                count++;

            if (count == k)
                maxAlter++;
        }
        return maxAlter;
    }
};