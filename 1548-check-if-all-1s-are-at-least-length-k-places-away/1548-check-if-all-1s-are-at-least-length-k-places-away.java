class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int n = nums.length;
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                continue;
            if (!q.isEmpty() && (i - q.poll() <= k))
                return false;
                
            if (nums[i] == 1)
                q.offer(i);
        }
        return true;
    }
}