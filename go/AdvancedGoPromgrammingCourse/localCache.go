// Write your answer here, and then test your code.
// Your job is to implement the Get and Set Cache methods.

package main

import (
	"errors"
)

// Change these boolean values to control whether you see
// the expected answer and/or hints.
const showExpectedResult = false
const showHints = false

type Key string
type Value string

type ValueWriter interface {
	Set(k Key, v Value)
}
type ValueReader interface {
	Get(k Key) (Value, error)
}

// Make any required changes to the Cache struct.
type Cache struct {
	size  int
	key   []Key
	value []Value
}

func NewCache() *Cache {
	return &Cache{}
}

func (c *Cache) Set(k Key, v Value) {
	for index, val := range c.key {
		if val == k {
			c.value[index] = v
			return
		}
	}
	currentSize := c.size
	c.size = currentSize + 1
	c.key = append(c.key, k)
	c.value = append(c.value, v)
	return
}

func (c *Cache) Get(k Key) (Value, error) {
	var this Value
	if c.size <= 0 {
		return this, errors.New("No items in Cache")
	}
	for index, val := range c.key {
		if val == k {
			this = c.value[index]
			return this, nil
		}
	}
	return this, errors.New("Key is unKnown")
}

func WriteValues(w ValueWriter, keys []Key, values []Value) {
	for i, k := range keys {
		w.Set(k, values[i])
	}
}

func ReadValues(r ValueReader, keys []Key) ([]Value, error) {
	values := make([]Value, len(keys))
	for i, k := range keys {
		v, err := r.Get(k)
		if err != nil {
			return nil, err
		}
		values[i] = v
	}

	return values, nil
}
