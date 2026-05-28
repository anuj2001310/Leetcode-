class Solution {
    public static class Trie {

        private class Node {
            char data;
            HashMap<Character, Node> child = new HashMap<>();
            boolean isTerminal;
            int idx = -1;

            int minLen = Integer.MAX_VALUE;
        }

        private Node root;

        public Trie() {
            Node nn = new Node();
            nn.data = '*';
            root = nn;
        }

        public void insert(String word, int ind) {
            if (word.length() < root.minLen) {

                root.minLen = word.length();

                root.idx = ind;
            }
            Node temp = root;
            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                if (!temp.child.containsKey(ch)) {

                    Node nn = new Node();
                    nn.data = ch;
                    temp.child.put(ch, nn);

                }
                temp = temp.child.get(ch);
                if (word.length() < temp.minLen) {
                    temp.minLen = word.length();
                    temp.idx = ind;
                }
            }
            temp.isTerminal = true;

        }

        public int getIndex(String prefix) {
            Node temp = root;
            int len = prefix.length();
            int ans = root.idx;
            for (int i = 0; i < len; i++) {
                char ch = prefix.charAt(i);
                if (!temp.child.containsKey(ch))
                    break;
                
                temp = temp.child.get(ch);
                ans = temp.idx;
            }
            return ans;
        }
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        Trie t = new Trie();
        int n = wordsContainer.length;
        for (int i = 0; i < n; i++)
            t.insert(rev(wordsContainer[i]), i);
        
        int[] arr = new int[wordsQuery.length];
        int i = 0;
        for (String a : wordsQuery) {
            int b = t.getIndex(rev(a));
            arr[i++] = b;
        }
        return arr;
    }

    public static String rev(String s) {
        return new StringBuilder(s).reverse().toString();
    }
}