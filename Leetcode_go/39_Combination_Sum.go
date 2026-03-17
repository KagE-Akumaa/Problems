package main

func combSum(ans *[][]int, temp []int, candidates []int, target int, start int, sum int) {
	if sum == target {
		comb := make([]int, len(temp))
		copy(comb, temp)

		*ans = append(*ans, comb)
		return
	}
	if sum > target {
		return
	}

	for i := start; i < len(candidates); i++ {
		sum += candidates[i]
		temp = append(temp, candidates[i])
		combSum(ans, temp, candidates, target, i, sum)
		sum -= temp[len(temp)-1]
		temp = temp[:len(temp)-1]
	}

}
func combinationSum(candidates []int, target int) [][]int {
	ans := [][]int{}
	temp := []int{}
	combSum(&ans, temp, candidates, target, 0, 0)
	return ans
}
func main() {
	arr := [][]int{}
	candidates := []int{2, 3, 6, 7}
	target := 7
	arr = combinationSum(candidates, target)

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			print(arr[i][j])
		}
		println()
	}
}
