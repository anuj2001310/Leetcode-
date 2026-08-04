class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int n = nums.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        boolean[] vis = new boolean[101];

        for (int g = 0; g < n; ++g) {
            min = Math.min(min, nums[g]);
            max = Math.max(max, nums[g]);
            vis[nums[g]] = true;
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = min; i < max; ++i) {
            if (!vis[i])
                ans.add(i);
        }
        return ans;
    }
}