class Solution {
    public long maxKelements(int[] nums, int k) {
        long ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int x : nums)
            pq.offer(x);
        while (k-- > 0) {
            int top = pq.poll();
            ans += top;
            pq.offer((int) Math.ceil(top / 3.0));
        }
        
        return ans;
    }
}