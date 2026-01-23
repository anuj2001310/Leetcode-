class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        vector<long long> a(nums.begin(), nums.end());
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        // Min heap: {sum, index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({a[i] + a[i + 1], i});
        }

        // Count inversions
        int inv = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1])
                inv++;
        }

        int ops = 0;

        while (inv > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = right[i];
            if (j == -1 || !alive[i] || !alive[j] || a[i] + a[j] != sum)
                continue;

            int L = left[i], R = right[j];

            // Remove old inversions
            if (L != -1 && a[L] > a[i])
                inv--;
            if (a[i] > a[j])
                inv--;
            if (R != -1 && a[j] > a[R])
                inv--;

            // Merge
            a[i] = sum;
            alive[j] = false;
            right[i] = R;
            if (R != -1)
                left[R] = i;

            // Add new inversions
            if (L != -1 && a[L] > a[i])
                inv++;
            if (R != -1 && a[i] > a[R])
                inv++;

            // Push new adjacent sums
            if (L != -1)
                pq.push({a[L] + a[i], L});
            if (R != -1)
                pq.push({a[i] + a[R], i});

            ops++;
        }

        return ops;
    }
};