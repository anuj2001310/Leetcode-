class Solution {
    private static int digitSum(int num) {
        int ans = 0;
        while (num != 0) {
            ans += (num % 10);
            num /= 10;
        }
        return ans;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;

        int[][] sorted = new int[n][2];
        for (int i = 0; i < n; i++) {
            sorted[i][0] = nums[i];
            sorted[i][1] = i;
        }

        Arrays.sort(sorted, (a, b) -> {
            int sumA = digitSum(a[0]);
            int sumB = digitSum(b[0]);
            if (sumA == sumB)
                return a[0] - b[0];
            return sumA - sumB;
        });

        boolean[] visited = new boolean[n];

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || sorted[i][1] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = sorted[j][1];
                cycleSize++;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
        return swaps;
    }
}