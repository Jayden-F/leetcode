package main

import "golang.org/x/exp/constraints"

// Ordering represents the result of a comparison: Less, Equal, or Greater
type Ordering int

const (
	Less Ordering = iota
	Equal
	Greater
)

func compare_function[T constraints.Ordered](want T) func(T) Ordering {
	return func(what T) Ordering {
		switch {
		case what < want:
			return Less
		case what > want:
			return Greater
		default:
			return Equal
		}
	}
}

func binary_search[T any](values []T, compare_fn func(T) Ordering) int {

	var low int = 0
	var high int = len(values)

	for low < high {

		var mid int = low + (high-low)/2
		var value T = values[mid]

		switch compare_fn(value) {
		case Greater:
			high = mid
		case Less:
			low = mid + 1
		case Equal:
			return mid
		}
	}
	return low

}

// func main() {
//
// 	var values []int = make([]int, 10)
//
// 	for i := range 10 {
// 		values[i] = i
// 	}
//
// 	println(binary_search(values, compare_function(10)))
//
// }
