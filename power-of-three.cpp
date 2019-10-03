func isPowerOfThree(n int) bool {
	s := strconv.FormatInt(int64(n), 3)
	return s[0] == '1' && len(s) - 1 == strings.Count(s, "0")
}
