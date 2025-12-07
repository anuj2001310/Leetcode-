class Solution {
    private int reflection(int num) {
        if (num == 0)
            return 0;
        int nnum = 0;

        //int reflected = 0;
        while (num > 0) {
            nnum = (nnum << 1) | (num & 1);
            num >>= 1;
        }
        return nnum;
    }

    public int[] sortByReflection(int[] nums) {
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        }); //[bit(reversed)-> int, int]

        for (int i = 0; i < n; ++i) {
            int reflected = reflection(nums[i]);
            pq.offer(new int[] { reflected, nums[i] });
        }

        int[] ans = new int[n];
        int id = 0;
        
        while (!pq.isEmpty()) {
            int top = pq.poll()[1];
            ans[id++] = top;
        }
        return ans;
    }
}