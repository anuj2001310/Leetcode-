class Solution {
    public int countMajoritySubarrays(int[] values, int key) {
        int size = values.length;
        int currentState = size + 1;

        int[] occurrence = new int[2 * size + 2];
        int[] cumulative = new int[2 * size + 2];

        occurrence[currentState] = 1;
        cumulative[currentState] = 1;

        int result = 0;

        for (int element : values) {
            if (element == key) {
                currentState++;
            } else {
                currentState--;
            }

            occurrence[currentState]++;

            cumulative[currentState] = cumulative[currentState - 1] + occurrence[currentState];

            result += cumulative[currentState - 1];
        }

        return result;
    }
}