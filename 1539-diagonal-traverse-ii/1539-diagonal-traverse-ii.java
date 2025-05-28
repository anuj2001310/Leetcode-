class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        int n = nums.size();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return b[1] - a[1];
            return a[0] - b[0];
        });

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums.get(i).size(); j++) {
                int sum = i + j;
                pq.offer(new int[] { sum, i, j });
            }
        }

        List<Integer> ans = new ArrayList<>();

        while (!pq.isEmpty()) {
            int r = pq.peek()[1];
            int c = pq.peek()[2];
            pq.poll();
            ans.add(nums.get(r).get(c));
        }

        int size = ans.size();
        var res = new int[size];
        for (int i = 0; i < size; i++)
            res[i] = ans.get(i);

        return res;
    }
}