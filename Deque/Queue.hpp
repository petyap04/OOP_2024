#pragma once
#include <iostream>
#include "Deque.hpp"

template <class T, class Container = Deque<T>>
class Queue
{
protected:
	Container c{};
public:
	Queue() = default;
	Queue(const Container& c);
	Queue(Container&& c);

	void push(const T& elem);
	void push(T&& elem);
	const T& peek()const;
	void pop();

	bool isEmpty()const;
};


template<class T, class Container>
Queue<T, Container>::Queue(const Container& c)
{
	this->c = c;
}

template<class T, class Container>
Queue<T, Container>::Queue(Container&& c)
{
	this->c = std::move(c);
}

template <class T, class Container>
void Queue<T, Container>::push(const T& elem)
{
	c.pushAtBack(elem);
}

template <class T, class Container>
void Queue<T, Container>::push(T&& elem)
{
	c.pushAtBack(std::move(elem));
}

template <class T, class Container>
const T& Queue<T, Container>::peek() const
{
	return c.peekAtFront();
}

template <class T, class Container>
void Queue<T, Container>::pop()
{
	c.popAtFront();
}

template <class T, class Container>
bool Queue<T, Container>::isEmpty() const
{
	return c.isEmpty();
}
