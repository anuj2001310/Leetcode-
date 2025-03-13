class Solution {
    
    static int distance(int x, int y) {
        return (int)Math.pow(x, 2) + (int)Math.pow(y, 2);
    }
    
    static class Pair {
        int dis;
        int[] point;
        Pair(int dis, int[] point) {
            this.dis = dis;
            this.point = point;
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        int n = points.length;
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.dis - b.dis);
        for (int i = 0; i < n; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dis = distance(x, y);
            pq.offer (new Pair(dis, points[i]));
        }
        
        int[][] ans = new int[k][];
        int idx = 0;
        while (k-- > 0 && !pq.isEmpty()) {
            Pair curr = pq.poll();
            ans[idx++] = curr.point;
        }
            
        return ans;
    }
}