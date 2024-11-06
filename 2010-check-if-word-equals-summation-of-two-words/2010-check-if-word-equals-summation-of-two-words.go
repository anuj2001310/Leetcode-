func change(str string) string {
    ch := ""
	for _, char := range str {
		curr := int(char - 'a')
		ch += strconv.Itoa(curr)
	}
	return ch
}
func isSumEqual(firstWord string, secondWord string, targetWord string) bool { 
    f := change(firstWord)
    s := change(secondWord)
    t := change(targetWord)

    fInt, _ := strconv.Atoi(f)
	sInt, _ := strconv.Atoi(s)
	tInt, _ := strconv.Atoi(t)
    return fInt + sInt == tInt
}