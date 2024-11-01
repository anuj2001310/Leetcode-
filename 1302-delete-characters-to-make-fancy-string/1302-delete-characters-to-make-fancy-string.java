class Solution {
    public String makeFancyString(String s) {
        StringBuilder sol = new StringBuilder();
        int i = 0;

        while (i < s.length()) {
            char ch = s.charAt(i);
            int count = 0;

            while (i < s.length() && s.charAt(i) == ch) {
                count++;
                i++;
            }

            if (count < 3) {
                sol.append(ch);
                if (count > 1)
                    sol.append(ch);

            } else
                sol.append(ch).append(ch);

        }

        return sol.toString();
    }
}