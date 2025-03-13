class Solution {
    private void applyQuery(int[] cnt, int[] query, int currentIndex) {
        int l = query[0], r = query[1], val = query[2];
        cnt[Math.max(l, currentIndex)] += val;
        cnt[r + 1] -= val;
    }

    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        var cnt = new int[n + 1];
        return processQueries(nums, queries, cnt);
    }

    private int processQueries(int[] nums, int[][] queries, int[] cnt) {
        int s = 0, k = 0;

        for (var i = 0; i < nums.length; ++i) {
            while (s + cnt[i] < nums[i]) {
                k++; // Increment k before accessing queries
                if (k - 1 >= queries.length)
                    return -1; // Not enough queries

                int[] query = queries[k - 1];
                if (query[1] < i)
                    continue; // Skip if query is irrelevant

                applyQuery(cnt, query, i);
            }
            s += cnt[i]; // Apply prefix sum logic
        }
        return k;
    }

}