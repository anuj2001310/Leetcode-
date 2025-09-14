class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exactWords = new HashSet<>(Arrays.asList(wordlist));
        Map<String, String> caseInsensitive = new HashMap<>();
        Map<String, String> vowelInsensitive = new HashMap<>();

        for (String word : wordlist) {
            String lower = word.toLowerCase();
            caseInsensitive.putIfAbsent(lower, word);

            String devoweled = devowel(lower);
            vowelInsensitive.putIfAbsent(devoweled, word);
        }

        String[] result = new String[queries.length];

        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];

            if (exactWords.contains(q)) {
                result[i] = q;
            } else {
                String lower = q.toLowerCase();
                if (caseInsensitive.containsKey(lower)) {
                    result[i] = caseInsensitive.get(lower);
                } else {
                    String devoweled = devowel(lower);
                    result[i] = vowelInsensitive.getOrDefault(devoweled, "");
                }
            }
        }

        return result;
    }

    private String devowel(String word) {
        StringBuilder sb = new StringBuilder();
        for (char ch : word.toCharArray()) {
            if ("aeiou".indexOf(ch) >= 0) {
                sb.append('*');
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}