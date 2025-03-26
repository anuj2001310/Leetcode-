class Solution {

    public int minOperations(int[][] grid, int x) {
        List<Integer> arr = new ArrayList<>();
        int r = 0;

        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] % x != grid[0][0] % x)
                    return -1;
                arr.add(grid[row][col]);
            }
        }

        Collections.sort(arr);

        int l = arr.size();
        int pre = 0;
        int suf = l - 1;

        while (pre < suf) {
            if (pre < l - suf - 1) {
                int p = ((pre + 1) * (arr.get(pre + 1) - arr.get(pre))) / x;
                r += p;
                pre++;
            } else {
                int s = ((l - suf) * (arr.get(suf) - arr.get(suf - 1))) / x;
                r += s;
                suf--;
            }
        }

        return r;
    }
}