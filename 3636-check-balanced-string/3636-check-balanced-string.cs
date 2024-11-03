public class Solution {
    public bool IsBalanced(string num) {
        var sum = 0;
        for (var i = 0; i < num.Length; ++i) {
            var dig = num[i] - '0';
            if ((i & 1) != 0)
                sum += dig;
            else
                sum -= dig;
        }
        return sum == 0;
    }
}