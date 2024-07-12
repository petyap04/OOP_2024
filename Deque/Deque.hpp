#pragma once
#include <iostream>
#include <deque>
template <class T>
class Deque
{
public:
	Deque();
	Deque(const Deque<T>& other);
	Deque(Deque<T>&& other);

	Deque& operator=(const Deque<T>& other);
	Deque& operator=(Deque<T>&& other);

	void pushAtFront(const T& elem);
	void pushAtFront(T&& elem);
	void pushAtBack(const T& elem);
	void pushAtBack(T&& elem);

	void popAtFront();
	void popAtBack();

	const T& peekAtFront()const;
	const T& peekAtBack()const;

	bool isEmpty()const;

	~Deque();
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	int front = -1;
	int rear = -1;
	void copyFrom(const Deque<T>& other);
	void moveFrom(Deque<T>&& other);
	void free();
	void resize(size_t newCap);
};

template<class T>
void Deque<T>::copyFrom(const Deque<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = static_cast<T*>(std::malloc(capacity * sizeof(T)));
	for (size_t i = 0; i < size; i++) {
		new (&data[i]) T(other.data[(other.front + i) % other.capacity]);
	}
	front = other.front;
	rear = other.rear;
}

template<class T>
void Deque<T>::moveFrom(Deque<T>&& other)
{
	size = other.size;
	capacity = other.capacity;
	data =  other.data;
	front = other.front;
	rear = other.rear;

	other.data = nullptr;
	other.size = other.capacity = other.front = other.rear = 0;
}

template<class T>
void Deque<T>::free()
{
	if (data) {
		for (size_t i = 0; i < size; ++i) {
			data[(front + i) % capacity].~T();
		}
		std::free(data);
	}
	data = nullptr;
	size = capacity = front = rear = 0;
}

template<class T>
void Deque<T>::resize(size_t newCap)
{
	T* newData = static_cast<T*>(std::malloc(newCap * sizeof(T)));
	for (size_t i = 0; i < size; ++i) {
		new (&newData[i]) T(std::move(data[(front + i) % capacity]));
		data[(front + i) % capacity].~T();
	}
	std::free(data);
	data = newData;
	capacity = newCap;
	front = 0;
	rear = size - 1;
}

template<class T>
Deque<T>::Deque()
{
	capacity = 8;
	data = static_cast<T*>(std::malloc(capacity * sizeof(T)));
}

template<class T>
Deque<T>::Deque(const Deque<T>& other)
{
	copyFrom(other);
}

template<class T>
Deque<T>::Deque(Deque<T>&& other)
{
	moveFrom(std::move(other));
}

template<class T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
{
	if(this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
inline Deque<T>& Deque<T>::operator=(Deque<T>&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
void Deque<T>::pushAtFront(const T& elem)
{
	if (size == capacity) {
		resize(capacity * 2);
	}
	if (front == 0) {
		front = capacity;
	}
	if (front == -1) {
		front = 1;
		rear = 0;
	}
	front = (front - 1 + capacity) % capacity;
	new (&data[front]) T(elem);
	size++;
}

template<class T>
void Deque<T>::pushAtFront(T&& elem)
{
	if (size == capacity) {
		resize(capacity * 2);
	}
	if (front == 0) {
		front = capacity;
	}
	if (front == -1) {
		front = 1;
		rear = 0;
	}
	front = (front - 1 + capacity) % capacity;
	new (&data[front]) T(std::move(elem));
	size++;
}

template<class T>
void Deque<T>::pushAtBack(const T& elem)
{
	if (size == capacity) {
		resize(capacity * 2);
	}
	if (rear == -1) {
		front = 0;
	}
	rear = (rear + 1) % capacity;
	new (&data[rear]) T(elem);
	size++;
}

template<class T>
void Deque<T>::pushAtBack(T&& elem)
{
	if (size == capacity) {
		resize(capacity * 2);
	}
	if (rear == -1) {
		front = 0;
	}
	rear = (rear + 1) % capacity;
	new (&data[rear]) T(std::move(elem));
	size++;
}

template<class T>
void Deque<T>::popAtFront()
{
	if (!isEmpty()) {
		data[front].~T();
		front = (front + 1) % capacity;
		size--;
	}
	else {
		throw std::runtime_error("Deque is empty");
	}
}

template<class T>
void Deque<T>::popAtBack()
{
	if (!isEmpty()) {
		data[rear].~T();
		rear = (rear - 1 + capacity) % capacity;
		size--;
	}
	else {
		throw std::runtime_error("Deque is empty");
	}
}

template<class T>
const T& Deque<T>::peekAtFront() const
{
	if (!isEmpty()) {
		return data[front];
	}
	throw std::runtime_error("Deque is empty");
}

template<class T>
const T& Deque<T>::peekAtBack() const
{
	if (!isEmpty()) {
		return data[rear];
	}
	throw std::runtime_error("Deque is empty");
}

template<class T>
bool Deque<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
Deque<T>::~Deque()
{
	free();
}

