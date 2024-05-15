template<class T>
class MyVector
{
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
	void free();
	void resize(int newCap);
public:
	MyVector() = default;
	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other);

	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other);

	void push_back(const T& elem);
	void push_back(T&& elem);
	void pop_back();

	void insert(const T& elem, int index);
	void erase(int index);

	void clear();

	~MyVector();
};

template<class T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<class T>
void MyVector<T>::moveFrom(MyVector<T>&& other) {
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<class T>
void MyVector<T>::free() {
	delete[]data;
	size = 0;
	capacity = 0;
}

template<class T>
void MyVector<T>::resize(int newCap) {
	T* newData = new T[capacity];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[]data;
	data = newData;
	capacity = newCap;
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	copyFrom(other);
}

template<class T>
MyVector<T>::MyVector(MyVector<T>&& other) {
	moveFrom(std::move(other));
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
void MyVector<T>::push_back(const T& elem) {
	if (size == capacity) {
		resize(2 * capacity);
	}
	if (capacity == 0) {
		resize(1);
	}
	data[size++] = elem;
}

template<class T>
void MyVector<T>::push_back(T&& elem) {
	if (size == capacity) {
		resize(2 * capacity);
	}
	if (capacity == 0) {
		resize(1);
	}
	data[size++] = std::move(elem);
}

template<class T>
void MyVector<T>::pop_back() {
	if (size == 0) {
		throw std::exception("Exception");
	}
	size--;
}

template<class T>
void MyVector<T>::insert(const T& elem, int index) {
	if (index >= size) {
		throw std::exception("Exception");
	}
	if (size == capacity) {
		resize(2 * capacity);
	}
	if (capacity == 0) {
		resize(1);
	}
	for (int i = size; i < index; i--) {
		data[index] = data[index + 1];
	}
	if (size * 2 < capacity) {
		resize(capacity / 2);
	}
}

template<class T>
void MyVector<T>::erase(int index) {
	if (index >= size) {
		throw std::exception("Exception");
	}
	for (int i = index; i < size; i++) {
		data[size] = data[size - 1];
	}
}

template<class T>
void MyVector<T>::clear() {
	delete[]data;
	size = 0;
	capacity = 0;
}

template<class T>
MyVector<T>::~MyVector()
{
	free();
}

int main()
{
    MyVector<int> v;
    v.push_back(4);
}
