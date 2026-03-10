class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> res = new ArrayList<>();
        char[] s = currentState.toCharArray();
        int n = s.length;

        for (int i = 0; i + 1 < n; i++) {
            if (s[i] != '+' || s[i + 1] != '+') {
                continue;
            }

            s[i] = '-';
            s[i + 1] = '-';
            res.add(new String(s));
            s[i] = '+';
            s[i + 1] = '+';
        }

        return res;
    }
}