class Solution {

    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int first = Integer.MIN_VALUE; //firstLargest rhombus sum
        int second = Integer.MIN_VALUE;
        int third = Integer.MIN_VALUE;

        //iterate through everything and treat each cell as center of rhombus
        //center is (row, col)
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                //get max rhombus size from this center cell. A size is valid if the four corners are in the grid
                int top = row + 1;
                int bottom = m - row;
                int left = col + 1;
                int right = n - col;

                int size = Math.min(Math.min(top, bottom), Math.min(left, right));

                for(int layer = 0; layer < size; layer++){ //calculate sums for all possible rhombuses at this center
                    //calculate curr rhombusSum
                    int sum = calculateSum(layer, row, col, grid);

                    //we want only distinct sums so ignore if sum is already recorded
                    if (sum == first || sum == second || sum == third) {
                        continue;
                    }

                    //store sum in the sorted
                    if (sum > first) {
                        // Shift everything down
                        third = second;
                        second = first;
                        first = sum;
                    } else if (sum > second) {
                        third = second;
                        second = sum;
                    } else if (sum > third) {
                        third = sum;
                    }

                }

            }
        }

        // Count how many valid top sums we actually have
        int count = 0;
        if (first != Integer.MIN_VALUE) count++;
        if (second != Integer.MIN_VALUE) count++;
        if (third != Integer.MIN_VALUE) count++;

        // Create array of the correct size
        int[] resultArray = new int[count];

        // Fill it (in order: first, second, third)
        int writeIndex = 0;

        if (first != Integer.MIN_VALUE) {
            resultArray[writeIndex] = first;
            writeIndex++;
        }
        if (second != Integer.MIN_VALUE) {
            resultArray[writeIndex] = second;
            writeIndex++;
        }
        if (third != Integer.MIN_VALUE) {
            resultArray[writeIndex] = third;
            writeIndex++;
        }
        return resultArray;
    }

    public int calculateSum(int s, int r, int c, int[][] grid) {
        //base case
        if (s == 0) {
            return grid[r][c];
        }

        int sum = 0;

        /*
         * Edge 1: TOP -> RIGHT (down-right diagonal)
         * Start at (r - s, c)
         * End just before (r, c + s)
         */
        for (int i = 0; i < s; i++) {
            sum += grid[r - s + i][c + i];
        }

        /*
         * Edge 2: RIGHT -> BOTTOM (down-left diagonal)
         * Start at (r, c + s)
         * End just before (r + s, c)
         */
        for (int i = 0; i < s; i++) {
            sum += grid[r + i][c + s - i];
        }

        /*
         * Edge 3: BOTTOM -> LEFT (up-left diagonal)
         * Start at (r + s, c)
         * End just before (r, c - s)
         */
        for (int i = 0; i < s; i++) {
            sum += grid[r + s - i][c - i];
        }

        /*
         * Edge 4: LEFT -> TOP (up-right diagonal)
         * Start at (r, c - s)
         * End just before (r - s, c)
         */
        for (int i = 0; i < s; i++) {
            sum += grid[r - i][c - s + i];
        }

        return sum;
    }

}