#pragma once
#include <iostream>

template <class T, unsigned S>
class Stack
{
	T data[S];
	size_t size = 0;
public:
	Stack() = default;
	void push(const T& something);
	void push(T&& something);

	void pop();
	const T& peek()const;
	bool isEmpty()const;
};

template<class T, unsigned S>
inline void Stack<T, S>::push(const T& something)
{
	if (size == S) {
		throw std::exception("jckdscnksd");
	}
	data[size++] = something;
}

template<class T, unsigned S>
inline void Stack<T, S>::push(T&& something)
{
	if (size == S) {
		throw std::exception("jckdscnksd");
	}
	data[size++] = std::move(something);
}

template<class T, unsigned S>
inline void Stack<T, S>::pop()
{
	if (isEmpty()) {
		throw std::exception("jckdscnksd");
	}
	size--;
}

template<class T, unsigned S>
inline const T& Stack<T, S>::peek() const
{
	return data[size - 1];
}

template<class T, unsigned S>
inline bool Stack<T, S>::isEmpty() const
{
	return size == 0;
}
