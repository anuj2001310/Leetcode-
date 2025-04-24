class Solution {
    public long calculateScore(String[] instructions, int[] values) {
        int n = values.length;
        var vis = new boolean[n];
        long sum = 0;
        for (int i = 0; i < n && i >= 0; ) {
            if (vis[i])
                break;
            vis[i] = true;
            if (instructions[i].equals("add")) {
                sum += values[i];
                i++;
            } else
                i += values[i];
        }
        return sum;
    }
}