/**
 * @param {number[]} nums
 * @return {string}
 */
var triangleType = function (nums) {
    let a = nums[0];
    let b = nums[1];
    let c = nums[2];

    if (a == b && b == c)
        return "equilateral";
    if ((a == b && a + b > c) || (b == c && b + c > a) || (a == c && a + c > b))
        return "isosceles";
    if (a + b > c && b + c > a && a + c > b)
        return "scalene";

    return "none";
};