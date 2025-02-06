class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int pro = nums[i] * nums[j];
                map.put (pro, map.getOrDefault(pro, 0) + 1);
            }
        }
        int w = 0;
        for (Map.Entry<Integer, Integer> h : map.entrySet()) {
            int f = h.getValue();
            if (f > 1)
                w += (f * (f - 1)) * 4;
        }
        return w;
    }
}