class Solution {
    class pair {
        String first;
        int second;

        pair(String first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String res : words)
            map.put(res, map.getOrDefault(res, 0) + 1);

        ArrayList<pair> pq = new ArrayList<>();
        for (Map.Entry<String, Integer> em : map.entrySet())
            pq.add(new pair(em.getKey(), em.getValue()));

        Collections.sort(pq, (a, b) -> {
            if (a.second == b.second)
                return a.first.compareTo(b.first);
            return b.second - a.second;
        });

        List<String> ans = new ArrayList<>();
        for (int i = 0; i < k; i++) {

            //System.out.print(pq.get(i).first + " " + pq.get(i).second);
            // System.out.println();
            ans.add(pq.get(i).first);
        }
        return ans;
    }
}