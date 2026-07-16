typedef long long ll;
typedef vector<int> vi;
#define Rep(a, b, c, d) for (int a = b; a < c; a += d)
#define all(nums) begin(nums), end(nums)
#define Sort(nums) sort(all(nums))
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = size(nums);
        vi prefixMax(n, -1);
        prefixMax[0] = nums[0];
        Rep(i, 1, n, 1) prefixMax[i] = fmax(prefixMax[i - 1], nums[i]);

        vi prefixGcd(n, -1);
        Rep(i, 0, n, 1) {
            int val = __gcd(prefixMax[i], nums[i]);
            prefixGcd[i] = val;
        }
        Sort(prefixGcd);
        int i = 0, j = n - 1;
        ll sum = 0;

        while (i < j) {
            int v = __gcd(prefixGcd[i], prefixGcd[j]);
            sum += v;
            i++;
            j--;
        }
        return sum;
    }
};