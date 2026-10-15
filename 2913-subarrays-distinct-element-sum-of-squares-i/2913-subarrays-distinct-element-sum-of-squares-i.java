class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            HashSet<Integer> help = new HashSet<>();
            
            for(int j = i; j < n; ++j){
                help.add(nums.get(j));
                ans += Math.pow(help.size(), 2);
            }
        }
        return ans;
    }
}