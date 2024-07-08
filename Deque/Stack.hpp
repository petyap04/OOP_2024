#pragma once
#include <iostream>
#include "Deque.hpp"

template <class T, class Container = Deque<T>>
class Stack {
protected:
	Container c;
public:
	Stack() = default;
	Stack(const Container& c);
	Stack(Container&& c);
	void put(const T& elem);
	void put(T&& elem);
	void pop();
	const T& peek() const;
	bool isEmpty()const;
};


template<class T, class Container>
Stack<T, Container>::Stack(const Container& c)
{
	this->c = c;
}

template<class T, class Container>
Stack<T, Container>::Stack(Container&& c)
{
	this->c = std::move(c);
}

template <class T, class Container>
void Stack<T,Container>::put(const T& elem)
{
	c.pushAtBack(elem);
}

template <class T, class Container>
void Stack<T, Container>::put(T&& elem)
{
	c.pushAtBack(std::move(elem));
}

template <class T, class Container>
void Stack<T, Container>::pop()
{
	c.popAtBack();
}

template <class T, class Container>
const T& Stack<T, Container>::peek() const
{
	return c.peekAtBack();
}

template <class T, class Container>
bool Stack<T, Container>::isEmpty() const
{
	return c.isEmpty();
}
