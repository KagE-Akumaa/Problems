package main

func isValid(str string) bool {
	l := 0
	r := len(str) - 1
	for l <= r {
		if str[l] != str[r] {
			return false
		}
		l++
		r--
	}
	return true
}
func backtrack(ans [][]string, temp []string, s string, start int) [][]string {
	if start == len(s) {
		p := make([]string, len(temp))
		copy(p, temp)
		ans := append(ans, p)
		return ans
	}
	for i := start; i < len(s); i++ {
		str := s[start : i+1]
		if !isValid(str) {
			continue
		}
		temp = append(temp, str)
		ans = backtrack(ans, temp, s, i+1)
		temp = temp[:len(temp)-1]
	}
	return ans
}
func partition(s string) [][]string {
	temp := []string{}
	return backtrack([][]string{}, temp, s, 0)
}
