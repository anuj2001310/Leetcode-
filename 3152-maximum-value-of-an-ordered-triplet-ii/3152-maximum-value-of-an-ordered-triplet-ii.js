 /* @param {number[]} nums
 * @return {number}
 */
var maximumTripletValue = function (nums) {
    let n = nums.length;
    var ans = 0, dmax = 0, imax = 0;
    for (let num of nums) {
        ans = Math.max(ans, dmax * num);
        dmax = Math.max(dmax, imax - num);
        imax = Math.max(imax, num);
    }
    return ans;
};