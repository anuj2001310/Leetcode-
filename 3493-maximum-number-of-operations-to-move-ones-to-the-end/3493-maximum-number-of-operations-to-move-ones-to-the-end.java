class Solution {
    public int maxOperations(String s) {
        int countedOnes = 0;
        int operations = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '1') {
                countedOnes++;
            } else {
                if (i == 0 || s.charAt(i - 1) == '1') {
                    operations += countedOnes;
                }
            }
        }
        return operations;
    }
}