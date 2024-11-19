func solve(n int, dp []int) int {
    if n == 0 || n == 1 {
		return n
	}
	if dp[n] != 0 {
		return dp[n]
	}
	dp[n] = solve(n - 1, dp) + solve(n - 2, dp)
	return dp[n]
}

	func fib(n int) int {
		dp := make([]int, 31)
		dp[0] = 0
		dp[1] = 1

		return solve(n, dp)
	}