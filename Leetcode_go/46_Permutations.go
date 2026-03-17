package main

func genPerm(ans [][]int, temp []int, visited []bool, nums []int) [][]int {
	if len(temp) == len(nums) {
		perm := make([]int, len(temp))
		copy(perm, temp)
		ans = append(ans, perm)
		return ans
	}
	for i := range nums {
		if visited[i] {
			continue
		}
		temp = append(temp, nums[i])
		visited[i] = true
		ans = genPerm(ans, temp, visited, nums)
		temp = temp[:len(temp)-1]
		visited[i] = false
	}
	return ans
}
func permute(nums []int) [][]int {
	visited := make([]bool, len(nums))
	return genPerm([][]int{}, []int{}, visited, nums)
}
