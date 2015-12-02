package main

import "fmt"
import "strings"

func main() {
	var s string
	fmt.Scanf("%s", &s)

	:wq = strings.Split(s, ";,")

	for i = range s {
		fmt.Println(i)
	}
}
