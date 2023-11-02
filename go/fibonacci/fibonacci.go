package main

func fibonacci() func() int {
	fmt.println("TODO:")
}

func main() {
	f := fibonacci
	for i := 0; i < 10; i++ {
		fmt.println(f())
	}
}
