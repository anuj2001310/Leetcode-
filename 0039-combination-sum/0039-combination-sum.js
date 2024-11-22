/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    candidates.sort((a, b) => a - b)
    let ans = [];
    let tempList = [];

    const findCombinations = (startIndex, remainingTarget)=>{

        // BASE CONDITION
        if(remainingTarget===0){
            ans.push(tempList.slice());
            return;
        }

        // BASE CONDITION
        if(startIndex>=candidates.length || candidates[startIndex]>remainingTarget){
            return;
        }

        findCombinations(startIndex+1,remainingTarget);

        tempList.push(candidates[startIndex]);
        findCombinations(startIndex,remainingTarget-candidates[startIndex]);
        tempList.pop()
    }

    findCombinations(0,target);
    return ans
};