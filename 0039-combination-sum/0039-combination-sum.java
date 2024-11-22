class Solution {
    private void find(int idx, int[] arr, int tar, List<List<Integer>> ans, List<Integer> ds) {
        if (idx == arr.length) {
            if (tar == 0)
                ans.add(new ArrayList<>(ds));
            return;
        }
        if (arr[idx] <= tar) {
            ds.add(arr[idx]);
            find(idx, arr, tar - arr[idx], ans, ds);
            ds.remove(ds.size() - 1);
        }
        find(idx + 1, arr, tar, ans, ds);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        find(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
}