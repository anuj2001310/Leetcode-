class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        });

        for (int i = 0; i < arr.length; i++) {
            int num = Math.abs(arr[i] - x);
            pq.offer(new int[] { num, arr[i] });
        }
        List<Integer> ans = new ArrayList<>();
        while (k-- > 0 && !pq.isEmpty()) {
            int val = pq.peek()[1];
            pq.poll();
            ans.add(val);
        }
        Collections.sort(ans, (a, b) -> a - b);
        return ans;
    }
}