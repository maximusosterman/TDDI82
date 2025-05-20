#pragma once

#include <cstddef>

template<typename T>
class CountedPtr
{
public:

    CountedPtr(T* ptr);
    CountedPtr();
    CountedPtr(CountedPtr<T> const& copied_ptr);
    ~CountedPtr();
    CountedPtr(CountedPtr<T>&& moved_ptr);

    CountedPtr<T>& operator=(const CountedPtr<T>& other);
    CountedPtr<T>& operator=(CountedPtr<T>&& other);
    CountedPtr<T>& operator=(std::nullptr_t n_ptr);
    CountedPtr<T>& operator*();
    CountedPtr<T>* operator->();
    bool operator==(CountedPtr<T> rhs);
    bool operator!=(CountedPtr<T> rhs);

    T* get();
    int use_count();

    void decrease_count();
    void increase_count();

private:
    T* ptr;
    int* count;

};
