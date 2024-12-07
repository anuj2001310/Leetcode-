/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
function check(mid, nums, op) {
    let c = 0;

    for (let i = 0; i < nums.length; i++) {
        c += Math.floor((nums[i] - 1) / mid);
        if (c > op) 
            return false;
    }
    return true;
}
var minimumSize = function (nums, op) {

    let x = 1;
    let y = Math.max(...nums);
    let res = x;
    while (x <= y) {
        let mid = Math.floor((x + y) / 2);
        if (check(mid, nums, op)) {
            res = mid;
            y = mid - 1;
        }
        else {
            x = mid + 1
        }
    }
    return res
};