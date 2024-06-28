#include <iostream>

template <class T>
class UniquePtr {
    T* ptr;

    void moveFrom(UniquePtr&& other);
    void free();
public:
    UniquePtr() = default;
    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other);

    UniquePtr<T>& operator=(const UniquePtr& other) = delete;
    UniquePtr<T>& operator=(UniquePtr&& other);

    T& operator* ();
    const T& operator*()const;

    ~UniquePtr();
};

template<class T>
void UniquePtr<T>::moveFrom(UniquePtr&& other)
{
    ptr = other.ptr;
    other.ptr = nullptr;
}

template<class T>
void UniquePtr<T>::free()
{
    delete ptr;
}

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr&& other)
{
    moveFrom(std::move(other));
}

template<class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(ptr));
    }
    return *this;
}

template<class T>
T& UniquePtr<T>::operator* ()
{
    return &ptr;
}

template<class T>
const T& UniquePtr<T>::operator*()const {
    return &ptr;
}

template<class T>
UniquePtr<T>::~UniquePtr()
{
    free();
}
