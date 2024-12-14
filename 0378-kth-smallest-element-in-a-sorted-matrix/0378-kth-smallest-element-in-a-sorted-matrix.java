class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int m = matrix[0].length;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pq.offer(matrix[i][j]);

        while (--k > 0 && pq.size() > 0)
            pq.poll();
        return pq.peek();
    }
}