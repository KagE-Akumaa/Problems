package main

func helper(ans [][]int, temp []int, n int, k int, start int) [][]int {
	if len(temp) == k {
		comb := make([]int, len(temp))
		copy(comb, temp)
		ans = append(ans, comb)
		return ans
	}
	if len(temp) > k {
		return ans
	}
	for i := start; i <= n; i++ {
		temp = append(temp, i)
		ans = helper(ans, temp, n, k, i+1)
		temp = temp[:len(temp)-1]
	}
	return ans

}
func combine(n int, k int) [][]int {
	temp := []int{}
	return helper([][]int{}, temp, n, k, 1)
}
