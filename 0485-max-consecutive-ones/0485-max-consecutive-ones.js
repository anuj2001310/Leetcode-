/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    var maxCount = 0;
        var count = 0;
        for(let i=0;i<nums.length;i++){
            if(nums[i]==1){
                count++;
                maxCount = Math.max(maxCount,count);
            }
            else 
            count = 0;
        }
        return maxCount;
};