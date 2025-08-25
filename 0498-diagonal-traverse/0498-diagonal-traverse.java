class Solution {
    public int[] findDiagonalOrder(int[][] nums) {
        Map<Integer, Deque<Integer>> map = new TreeMap<>();
        int n = nums.length;
        int m = nums[0].length;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = i + j;
                
                map.putIfAbsent(sum, new ArrayDeque<>());

                if ((sum & 1) == 0)
                    map.get(sum).addFirst(nums[i][j]);
                else
                    map.get(sum).addLast(nums[i][j]);  
                
            }
        }
        int[] ans = new int[n * m];
        int idx = 0;
        for (Map.Entry<Integer, Deque<Integer>> em : map.entrySet()) {
            Deque<Integer> dq = em.getValue();
            while (!dq.isEmpty()) {
                int num = dq.pollFirst();
                ans[idx++] = num;
            }
        }
        return ans;
    }
}