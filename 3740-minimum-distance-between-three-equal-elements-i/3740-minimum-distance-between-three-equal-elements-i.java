class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++)
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        
        int ans = Integer.MAX_VALUE;
        for (Map.Entry<Integer, List<Integer>> em : map.entrySet()) {
            List<Integer> lst = em.getValue();
            int temp = 0;
            for (int i = 0; i < lst.size() - 2; i++) {
                temp = Math.abs(lst.get(i) - lst.get(i + 1)) + Math.abs(lst.get(i + 1) - lst.get(i + 2)) + Math.abs(lst.get(i + 2) - lst.get(i));
                ans = Math.min(ans, temp);
            }
        }
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}