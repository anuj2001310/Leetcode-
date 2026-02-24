class Solution {
    public List<Integer> toggleLightBulbs(List<Integer> bulbs) {
        int n = bulbs.size();
        List<Integer> ans = new ArrayList<>();
        var map = new boolean[101];

        for (int i = 0; i < n; i++) {
            if (map[bulbs.get(i)])
                map[bulbs.get(i)] = false;
            else
                map[bulbs.get(i)] = true;
        }

        for (int i = 0; i < 101; ++i)
            if (map[i])
                ans.add(i);

        return ans;
    }
}