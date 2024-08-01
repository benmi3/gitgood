package main

import (
	"fmt"

	"github.com/benmi3/go-starting-template/greetings"
)

func main() {
    // Get a greeting message and print it.
    message := greetings.Hello("Gladys")
    fmt.Println(message)
}
