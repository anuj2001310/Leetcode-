class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = nums[0], nums[1], nums[2]
        if a == b and b == c:
            return "equilateral"
        if (a == b and a + b > c) or (b == c and b + c > a) or (a == c and a + c > b):
            return "isosceles"
        if a + b > c and b + c > a and a + c > b:
            return "scalene"
        return "none"