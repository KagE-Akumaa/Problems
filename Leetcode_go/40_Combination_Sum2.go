package main

import "sort"

func combSum2(ans [][]int, temp []int, candidates []int, target int, start int) [][]int {
	if target == 0 {
		comb := make([]int, len(temp))
		copy(comb, temp)
		ans = append(ans, comb)
		return ans
	}
	if target < 0 {
		return ans
	}

	for i := start; i < len(candidates); i++ {
		if i > start && candidates[i] == candidates[i-1] {
			continue
		}
		temp = append(temp, candidates[i])
		ans = combSum2(ans, temp, candidates, target-candidates[i], i+1)
		temp = temp[:len(temp)-1]
	}
	return ans
}
func combinationSum2(candidates []int, target int) [][]int {
	temp := []int{}
	sort.Ints(candidates)
	ans := combSum2([][]int{}, temp, candidates, target, 0)
	return ans
}
