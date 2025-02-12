class Solution {
public:
    int maximumSum(vector<int>& nums) {
        long answer = -1;
    
        int map[82] = {};
        long n;
        for (long num : nums) {
            n = helper(num);
            if (map[n] && answer < (map[n] + num))
                answer = map[n] + num;
            map[n] = (num > map[n]) ? num : map[n];
        }
        return answer;
    }

private:
    long helper(long num) {
        long answer = 0;
        while (num) {
            answer += num % 10;
            num /= 10;
        }
        return answer;
    }
};