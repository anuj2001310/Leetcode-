class Solution {
    private int reverse(int num) {
        int r = 0;
        while (num > 0) {
            r = r * 10 + num % 10;
            num /= 10;
        }
        return r;
    }

    public int minMirrorPairDistance(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int r = 0, ans = Integer.MAX_VALUE;

        for (; r < n; ++r) {
            if (map.containsKey(nums[r]))
                ans = Math.min(ans, r - map.get(nums[r]));

            int rev = reverse(nums[r]);
            map.put(rev, r);
        }
        /*
        for (Map.Entry<Integer, Integer> em : map.entrySet())
            System.out.println("Key : " + em.getKey() + ". Value : " + em.getValue());
        System.out.println(ans);
        */
        return ((ans == Integer.MAX_VALUE) ? -1 : ans);
    }
}