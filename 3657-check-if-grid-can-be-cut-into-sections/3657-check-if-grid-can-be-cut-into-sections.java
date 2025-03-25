class Solution {
    private boolean help(int[][] rectangles, int dim) {
        int gap = 0;
        Arrays.sort(rectangles, (a, b) -> a[dim] - b[dim]);
        int furthestEnd = rectangles[0][dim + 2];

        for (int i = 1; i < rectangles.length; i++) {
            int[] rect = rectangles[i];

            if (furthestEnd <= rect[dim])
                gap++;

            furthestEnd = Math.max(furthestEnd, rect[dim + 2]);
        }

        return gap >= 2;
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        return help(rectangles, 0) || help(rectangles, 1);
    }
}