class Solution {
    int[] d;
    int maxN;
    TreeSet<Integer> positions = new TreeSet<>();

    public List<Boolean> getResults(int[][] que) {
        maxN = Math.min(5 * (int) 1e4, 3 * que.length);

        d = new int[maxN + 1];
        Segment ds = new Segment(maxN);

        List<Boolean> ans = new ArrayList<>();

        for (int[] q : que) {
            int type = q[0];

            // type 1
            if (type == 1) {
                int pos = q[1];
                Integer left = lb(pos);
                Integer right = ub(pos);

                if (left != null) {
                    d[left] = pos - left;
                    ds.update(0, maxN + 1, 0, left, d[left]);
                }
                if (right != null) {
                    d[pos] = right - pos;
                } else {
                    d[pos] = Integer.MAX_VALUE;
                }

                ds.update(0, maxN + 1, 0, pos, d[pos]);
                positions.add(pos);
            } else {
                // type 2
                int pos = q[1];
                int sz = q[2];

                // int max = ds.query(0 ,maxN+1 ,0 ,0 ,pos);
                Integer prev = lb(pos); // if nothing is inserted
                if (prev == null) {
                    if (pos >= sz)
                        ans.add(true);
                    else
                        ans.add(false);

                    continue;
                }
                int min = positions.first();
                if (Math.min(min, pos) >= sz) {
                    ans.add(true);
                    continue;
                }
                int p = prev;
                if (pos - p >= sz) {
                    ans.add(true);
                    continue;
                }
                int max = ds.query(0, maxN + 1, 0, 0, p - 1);

                if (max == 0) {
                    if (p >= sz)
                        ans.add(true);
                    else
                        ans.add(false);
                    continue;
                }
                if (max >= sz) {
                    ans.add(true);
                } else
                    ans.add(false);
            }
        }

        return ans;
    }

    public Integer ub(int tar) {
        return positions.ceiling(tar);
    }

    public Integer lb(int tar) {
        return positions.floor(tar);
    }
}

class Segment {
    int[] tree;
    int n;

    public Segment(int n) {
        this.n = n;
        this.tree = new int[4 * n];
        // Arrays.fill(tree ,Integer.MAX_VALUE);
    }

    public void update(int left, int right, int idx, int qIdx, int val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }

        int m = left + (right - left) / 2;

        if (m >= qIdx) {
            update(left, m, 2 * idx + 1, qIdx, val);
        } else {
            update(m + 1, right, 2 * idx + 2, qIdx, val);
        }

        tree[idx] = Math.max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    public int query(int left, int right, int idx, int qleft, int qright) {
        if (left >= qleft && right <= qright) {
            return tree[idx];
        }

        if (left > qright || right < qleft) {
            return Integer.MIN_VALUE;
        }

        int m = left + (right - left) / 2;
        int leftSub = query(left, m, 2 * idx + 1, qleft, qright);
        int rightSub = query(m + 1, right, 2 * idx + 2, qleft, qright);

        return Math.max(leftSub, rightSub);
    }
}