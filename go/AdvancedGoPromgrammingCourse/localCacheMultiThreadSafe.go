// Write your answer here, and then test your code.
// Your job is to implement the Get and Set Cache methods.

package main

import (
	"errors"
	"sync"
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
	values map[Key]Value
	lock   sync.RWMutex
}

func NewCache() *Cache {
	return &Cache{
		values: make(map[Key]Value),
	}
}

func (c *Cache) Set(k Key, v Value) {
	c.lock.Lock()
	defer c.lock.Unlock()
	c.values[k] = v
	return
}

func (c *Cache) Get(k Key) (Value, error) {
	c.lock.RLock()
	defer c.lock.RUnlock()

	v, ok := c.values[k]
	if !ok {
		return Value(""), errors.New("Key is unKnown")
	}
	return v, nil
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
