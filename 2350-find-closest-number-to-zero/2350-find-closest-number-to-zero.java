class Solution {
    public int findClosestNumber(int[] nums) {
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return b[1] - a[1];
            return a[0] - b[0];
        });
        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i] - 0);
            pq.offer(new int[] { num, nums[i] });
        }
        return pq.peek()[1];
    }
}