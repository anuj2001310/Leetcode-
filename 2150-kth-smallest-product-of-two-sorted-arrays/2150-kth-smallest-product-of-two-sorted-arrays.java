class Solution {
    long noSol;
    Map<long[], Long> memory;

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        noSol = 1 << 20;
        noSol = noSol * noSol;
        noSol = -noSol;

        List<Integer> neg1 = new ArrayList();
        List<Integer> neg2 = new ArrayList();
        List<Integer> pos1 = new ArrayList();
        List<Integer> pos2 = new ArrayList();
        Comparator<long[]> cmp = (long[] a, long[] b) -> {
            if (a[0] == b[0]) {
                if (a[1] == b[1]) {
                    return Long.compare(a[2], b[2]);
                }
                return Long.compare(a[1], b[1]);
            }
            return Long.compare(a[0], b[0]);
        };
        memory = new TreeMap(cmp);

        int n = nums1.length;
        int m = nums2.length;
        int i, j;

        for (i = 0; i < n; i++) {
            if (nums1[i] < 0) {
                neg1.add(nums1[i]);
            } else
                pos1.add(nums1[i]);
        }
        for (i = 0; i < m; i++) {
            if (nums2[i] < 0) {
                neg2.add(nums2[i]);
            } else
                pos2.add(nums2[i]);
        }

        if (k <= neg1.size() * pos2.size() + neg2.size() * pos1.size()) {
            Collections.reverse(pos2);
            Collections.reverse(pos1);
            return findKth(neg1, pos2, neg2, pos1, k);
        }
        Collections.reverse(neg1);
        Collections.reverse(neg2);
        return findKth(neg1, neg2, pos1, pos2, k - (neg1.size() * pos2.size() + neg2.size() * pos1.size()));

    }

    long findKth(List<Integer> arr1, List<Integer> arr2, List<Integer> arr3, List<Integer> arr4, long k) {
        long max = 1 << 20;
        max = max * max;
        long min = -max;
        long ans = max;
        while (min <= max) {
            long mid = (min + max) / 2;
            long lc = count(arr1, arr2, mid);
            long rr = count(arr3, arr4, mid);

            if (lc + rr < k) {
                min = mid + 1;
            } else {
                ans = mid;
                max = mid - 1;
            }

        }
        return ans;

    }

    long count(List<Integer> arr1, List<Integer> arr2, long k) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0;
        int j = m - 1;
        long co = 0;
        while (i < n && j >= 0) {
            if ((long) arr1.get(i) * (long) arr2.get(j) <= k) {
                co += (j + 1);
                i++;
            } else {
                j--;
            }

        }
        return co;
    }

}