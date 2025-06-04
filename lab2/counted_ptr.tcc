// Komplettering: Funktioner som är konstanta ska innebära att man inte kan ändra på datan pekar på.
// Det ska finnas två varianter av ´operator*´, ´operator->´ och ´get()´
// en för när pekaren är konstant och en när den inte är det.
// och det är bara med hjälp av den icke-konstanta varianten som användaren får ändra på den underliggande datan.

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
    decrease_count();
}

template <typename T>
CountedPtr<T>::CountedPtr(CountedPtr&& other) noexcept
    : ptr(other.ptr), count(other.count)
{
    other.ptr = nullptr;
    other.count = nullptr;
}


template <typename T>
void CountedPtr<T>::decrease_count() {
    if (count) {
        --(*count);
        if (*count == 0) {
            delete ptr;
            delete count;
        }
        count = nullptr;
        ptr = nullptr;
    }
}

template <typename T>
void CountedPtr<T>::increase_count()
{
    ++(*count);
    if (count == 0)
    {
        delete this;
    }
}

template <typename T>
CountedPtr<T>& CountedPtr<T>::operator=(const CountedPtr<T>& other)
{
    if (this != &other) {
        decrease_count();

        ptr = other.ptr;
        count = other.count;

        if (count)
            ++(*count);
    }
    return *this;
}

template <typename T>
CountedPtr<T>& CountedPtr<T>::operator=(CountedPtr&& other) noexcept
{
    if (this != &other) {
        decrease_count();
        ptr = other.ptr;
        count = other.count;
        other.ptr = nullptr;
        other.count = nullptr;
    }
    return *this;
}

template <typename T>
CountedPtr<T>& CountedPtr<T>::operator=(std::nullptr_t)
{
    decrease_count();
    ptr = nullptr;
    count = nullptr;
    return *this;
}

template <typename T>
T& CountedPtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T* CountedPtr<T>::operator->() const
{
    return ptr;
}

template <typename T>
T& CountedPtr<T>::operator*()
{
    return *ptr;
}

template <typename T>
T* CountedPtr<T>::operator->()
{
    return ptr;
}

template <typename T>
T* CountedPtr<T>::get() const
{
    return ptr;
}

template <typename T>
T* CountedPtr<T>::get()
{
    return ptr;
}

template <typename T>
int CountedPtr<T>::use_count()
{
    if (count == nullptr)
    {
        return 0;
    }

    return *count;
}

template <typename T>
bool CountedPtr<T>::operator==(CountedPtr<T> rhs) const
{
    return (this->get() == rhs.get());
}

template <typename T>
bool CountedPtr<T>::operator!=(CountedPtr<T> rhs) const
{
    return !(this->get() == rhs.get());
}

template <typename T>
bool CountedPtr<T>::operator==(T* rhs)
{
    return (this->get() == rhs);
}

template <typename T>
bool CountedPtr<T>::operator!=(T* rhs)
{
    return !(this->get() == rhs);
}
