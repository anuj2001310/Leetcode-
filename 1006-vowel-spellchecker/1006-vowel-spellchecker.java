class Solution {
    static final int GAP = 'a' - 'A';

    public String[] spellchecker(String[] wordlist, String[] queries) {
        Map<Long, String> wordMap = new HashMap<>(wordlist.length << 1), capMap = new HashMap<>(wordlist.length << 1),
                vowelMap = new HashMap<>(wordlist.length << 1);
        for (String word : wordlist) {
            long hash = 0, capHash = 0, vowelHash = 0;
            for (int i = 0, length = word.length(), c; i < length;) {
                hash = (hash << 7) | (c = word.charAt(i++));
                capHash = (capHash << 7) | (c < 'a' ? c += GAP : c);
                vowelHash = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? (vowelHash << 7)
                        : (vowelHash << 7) | c;
            }
            wordMap.put(hash, word);
            capMap.putIfAbsent(capHash, word);
            vowelMap.putIfAbsent(vowelHash, word);
        }
        for (int i = 0; i < queries.length; i++) {
            long hash = 0, capHash = 0, vowelHash = 0;
            for (int j = 0, length = queries[i].length(), c; j < length;) {
                hash = (hash << 7) | (c = queries[i].charAt(j++));
                capHash = (capHash << 7) | (c < 'a' ? c += GAP : c);
                vowelHash = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? (vowelHash << 7)
                        : (vowelHash << 7) | c;
            }
            if (wordMap.containsKey(hash))
                continue;
            String word = capMap.get(capHash);
            queries[i] = word != null ? word : vowelMap.getOrDefault(vowelHash, "");
        }
        return queries;
    }
}