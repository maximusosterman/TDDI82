#include "counted_ptr.h"


template <typename T>
CountedPtr<T>::CountedPtr(T* ptr)
    : ptr{ptr}, count{nullptr}
{
    if (ptr) {
        count = new int{1};
    }
}

template <typename T>
CountedPtr<T>::CountedPtr()
           : ptr {nullptr}, count {nullptr}
{}

template <typename T>
CountedPtr<T>::CountedPtr(CountedPtr<T> const& copied_ptr)
            : ptr {copied_ptr.ptr}, count {copied_ptr.count}
{
    increase_count();
}

template <typename T>
CountedPtr<T>::~CountedPtr()
{
    delete ptr;
    delete count;
}

template <typename T>
CountedPtr<T>::CountedPtr(CountedPtr<T>&& moved_ptr)
            : ptr {moved_ptr.ptr}, count {moved_ptr.count}
{
    decrease_count();
    delete moved_ptr;
}

template <typename T>
void CountedPtr<T>::decrease_count()
{
    count--;
    if (count == 0)
    {
        delete this;
    }
}

template <typename T>
void CountedPtr<T>::increase_count()
{
    count++;
    if (count == 0)
    {
        delete this;
    }
}
