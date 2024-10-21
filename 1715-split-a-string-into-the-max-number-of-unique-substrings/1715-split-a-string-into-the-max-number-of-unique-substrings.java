class Solution {
    private char[] cs;
    private int n;
    private int res;

    public int maxUniqueSplit(String s) {
        cs = s.toCharArray();
        n = cs.length;
        dfs(0, 0, new HashSet<>());
        return res;
    }

    private void dfs(int hash, int i, Set<Integer> vis) {
        if (i == n) {
            res = Math.max(res, vis.size());
            return;
        }
        hash = hash * 131 + cs[i];
        if (!vis.contains(hash)) {
            vis.add(hash);
            dfs(0, i + 1, vis);
            vis.remove(hash);
        }
        dfs(hash, i + 1, vis);
    }

}