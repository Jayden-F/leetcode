package main

import (
	"fmt"
)

// fib computes Fibonacci numbers recursively.
func fib(x int) int {
	if x == 0 || x == 1 {
		return x
	}
	return fib(x-1) + fib(x-2)
}

// fibAsync simulates asynchronous Fibonacci computation using a goroutine.
// It sends the result through a channel when done.
func fibAsync(x int, resultChan chan int) {
	fmt.Println("running async")
	result := fib(x)
	fmt.Println("finished async")
	resultChan <- result
}

func main() {
	fmt.Println("starting")

	// Create a channel to receive async fib result
	resultChan := make(chan int)

	// Start async fib calculation in a goroutine
	go fibAsync(51, resultChan)

	fmt.Println("running y")
	y := fib(50)
	fmt.Println("finished y")

	// Wait for async result
	x := <-resultChan

	fmt.Println(x)
	fmt.Println(y)
}
