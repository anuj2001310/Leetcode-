class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size())
            return false;
        int sum = 0;
        for(auto n : nums)
            sum += n;
        //impossible to partition
        if(k > sum || sum%k != 0)
            return false;
        //sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        //target is the sum can be distributed to k bukets
        int target = sum/k;
        vector<int> buckets(k, 0);
        return backtrack(nums, 0, target, buckets);
    }
    bool backtrack(vector<int>& nums, int index, int target, vector<int>& buckets){
        //base line
        if(index == nums.size()){
            for(auto b : buckets){
                if( b != target)
                    return false;
            }
            return true;
        }
        //backtracking recursion
        for(int i = 0, n = buckets.size(); i < n; i++){
            //the bucket is full
            if(buckets[i] + nums[index] > target)
                continue;
            buckets[i] += nums[index];
            //once found a candidate, just return
            if(backtrack(nums, index+1, target, buckets))
               return true;
               
            buckets[i] -= nums[index];
			//extra prunning
            if(buckets[i] == 0)
                break;
        }
        return false;
    }
};