// Write your answer here, and then test your code.
// Your job is to implement the Add(index int, v T) method.

package main

import (
	"errors"
	"fmt"
)

// Change these boolean values to control whether you see
// the expected answer and/or hints.
const showExpectedResult = false
const showHints = false

type Node[T any] struct {
	value      T
	next, prev *Node[T]
}

type DoublyLinkedList[T any] struct {
	size int
	head *Node[T]
	tail *Node[T]
}

// Add appends the given value at the given index.
// Returns an error in the case that the index exceeds the list size.
func (l *DoublyLinkedList[T]) Add(index int, v T) error {
	currentSize := l.size
	if index > currentSize {
		return errors.New("To big index")
	}
	newElement := &Node[T]{
		value: v,
	}
	l.size = currentSize + 1

	if l.head == nil {
		l.head, l.tail = newElement, newElement
		return nil
	}
	if index == 0 {
		newElement.next = l.head
		l.head.prev, l.head = newElement, newElement
		return nil
	}

	if index == currentSize {
		newElement.prev = l.tail
		l.tail.next, l.tail = newElement, newElement
		return nil
	}
	current := l.head
	for i := 1; i < index; i++ {
		current = current.next
	}
	newElement.prev = current
	newElement.next = current.next
	current.next.prev, current.next = newElement, newElement

	return nil
}

func (l *DoublyLinkedList[T]) AddElements(elements []struct {
	index int
	value T
}) error {
	for _, e := range elements {
		if err := l.Add(e.index, e.value); err != nil {
			return err
		}
	}

	return nil
}

func (l *DoublyLinkedList[T]) PrintForward() string {
	if l.size == 0 {
		return ""
	}
	current := l.head
	output := "HEAD"
	for current != nil {
		output = fmt.Sprintf("%s -> %v", output, current.value)
		current = current.next
	}

	return fmt.Sprintf("%s -> NULL", output)
}

func (l *DoublyLinkedList[T]) PrintReverse() string {
	if l.size == 0 {
		return ""
	}
	current := l.tail
	output := "NULL"
	for current != nil {
		output = fmt.Sprintf("%s <- %v", output, current.value)
		current = current.prev
	}
	return fmt.Sprintf("%s <- HEAD", output)
}
func main() {
	// This is how your code will be called.
	// Your answer should respect the linked list order.
	// You can edit this code to try different testing cases.
	testCases := []struct {
		index int
		value string
	}{
		{index: 0, value: "C"},
		{index: 0, value: "A"},
		{index: 1, value: "B"},
		{index: 3, value: "D"},
	}
	dl := &DoublyLinkedList[string]{}
	err := dl.AddElements(testCases)
	forwardPrint := dl.PrintForward()
	reversePrint := dl.PrintReverse()
	println(err)
	fmt.Println(forwardPrint)
	fmt.Println(reversePrint)
}
