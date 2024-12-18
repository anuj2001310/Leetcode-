class Solution {
    static class pair {
        int first;
        int second;
        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int x : nums)
            map.put (x, map.getOrDefault(x, 0) + 1);
        
        PriorityQueue<pair> pq = new PriorityQueue<>((a, b)-> (b.first - a.first));
        for (Map.Entry<Integer, Integer> it : map.entrySet())
            pq.offer (new pair(it.getValue(), it.getKey()));
        
        int[] ans = new int[k];
        int idx = 0;
        while (k-- > 0 && pq.size() > 0) {
            int x = pq.peek().second;
            pq.poll();
            ans[idx++] = x;
        }
        return ans;
    }
}