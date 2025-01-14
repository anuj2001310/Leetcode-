func findThePrefixCommonArray(A []int, B []int) []int {
    n := len(A)
    ans := make([]int, n)

    presentA := make([]bool, n + 1)
    presentB := make([]bool, n + 1)
    cnt := 0

    for i := 0; i < n; i++ {
        if A[i] == B[i] {
            cnt++
        }
        if presentA[B[i]] {
            cnt++
        }
        if presentB[A[i]] {
            cnt++
        }

        presentA[A[i]] = true
        presentB[B[i]] = true

        ans[i] = cnt
    }
    return ans
}