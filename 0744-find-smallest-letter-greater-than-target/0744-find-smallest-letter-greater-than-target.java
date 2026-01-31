class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        for (int u = 0; u < n; ++u) {
            if (letters[u] > target)
                return letters[u];
        }
        return letters[0];
    }
}