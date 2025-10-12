# sample 963 ms submission
MOD = 10 ** 9 + 7


class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)
        MAX_EXP = n + 6

        power = []
        for num in nums:
            arr = [1] * (m + 1)
            for exp in range(1, m + 1):
                arr[exp] = arr[exp - 1] * num % MOD
            power.append(arr)

        fact = [1] * (m + 1)
        inv_fact = [1] * (m + 1)
        for i in range(1, m + 1):
            fact[i] = fact[i - 1] * i % MOD
        inv_fact[m] = pow(fact[m], MOD - 2, MOD)
        for i in range(m, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD

        dp = [[[0] * (m + 1) for _ in range(k + 1)] for __ in range(m + 1)]
        dp[0][0][m] = 1

        for j in range(MAX_EXP + 1):
            new_dp = [[[0] * (m + 1) for _ in range(k + 1)] for __ in range(m + 1)]
            for c in range(m + 1):
                for b in range(k + 1):
                    for r in range(m + 1):
                        val = dp[c][b][r]
                        if val == 0:
                            continue
                        if j < n:
                            for f in range(r + 1):
                                total = f + c
                                d_j = total & 1
                                carry_next = total >> 1
                                new_b = b + d_j
                                if new_b > k:
                                    continue
                                new_r = r - f
                                factor = power[j][f] * inv_fact[f] % MOD
                                new_val = val * factor % MOD
                                new_dp[carry_next][new_b][new_r] = (
                                    new_dp[carry_next][new_b][new_r] + new_val
                                ) % MOD
                        else:
                            total = 0 + c
                            d_j = total & 1
                            carry_next = total >> 1
                            new_b = b + d_j
                            if new_b > k:
                                continue
                            new_r = r
                            new_val = val
                            new_dp[carry_next][new_b][new_r] = (
                                new_dp[carry_next][new_b][new_r] + new_val
                            ) % MOD
            dp = new_dp

        ans = dp[0][k][0] * fact[m] % MOD
        return ans
