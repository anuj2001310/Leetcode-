class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int i = 0;
        int n = s.length();
        var map = new HashMap<String, String>();
        for (var v : knowledge) {
            String a = v.get(0), b = v.get(1);

            map.put(a, b);
        }
        StringBuilder sb = new StringBuilder("");
        while (i < n) {
            if (s.charAt(i) == '(') {
                String t = "";
                int j = i + 1;
                while (s.charAt(j) != ')' && j < n)
                    t += s.charAt(j++);

                i = j;

                sb.append(map.getOrDefault(t, "?"));
            } else
                sb.append(s.charAt(i));

            i++;
        }
        return sb.toString();
    }
}