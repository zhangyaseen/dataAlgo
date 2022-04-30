package main

import (
	"fmt"
	"math/rand"
	"time"
)


func findVal(array [20]int, val int) (key int, reason string) {
	fmt.Println("finding: ", val)
	for index, value := range array {
		if val == value {
			return index,""
		}
	}

	return -1, "not Found"
}

func delVal(array *[20]int, val int) (reason string) {
	fmt.Println("deleteing:", val)

	var pos int
	for index, value := range array {
		if val == value {
			pos = index
			break
		}
	}

	if pos == len(array) {
		return "not found"
	}

	for i := pos; i < len(array) -1 ; i++ {
		(*array)[i] = (*array)[i+1]
	}

	return ""
}

func insertValueBefor(array *[20]int, pos, val int) (reason string) {
	fmt.Println("insert val:", pos, val)

	if pos == len(array) || pos < 0 {
		return "insert error, pos error"
	}

	for i := len(array)-1 ; i > pos; i-- {
		(*array)[i] = (*array)[i-1]
	}

	(*array)[pos] = val

	return ""
}


func main() {
	rand.Seed(time.Now().Unix())
	array := [20]int{1, 2, 3, 4, 5, 6, 7, 8, 9}

	key, reason := findVal(array, rand.Intn(10))
	if reason == "" {
		fmt.Println("key:", key)
	} else {
		fmt.Println("find error:", reason)
	}
	
	reason = delVal(&array, rand.Intn(10))
	if reason == "" {
		fmt.Println("array:", array)
	} else {
		fmt.Println("delete error:", reason)
	}

	reason = insertValueBefor(&array, rand.Intn(10), rand.Intn(100))
	if reason == "" {
		fmt.Println("new array:", array)
	} else {
		fmt.Println("error:", reason)
	}
}