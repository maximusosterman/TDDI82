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
    CountedPtr(CountedPtr&& other) noexcept;

    CountedPtr<T>& operator=(const CountedPtr<T>& other);
    CountedPtr& operator=(CountedPtr&& other) noexcept;
    CountedPtr<T>& operator=(std::nullptr_t n_ptr);
    T& operator*() const;
    T* operator->() const;
    bool operator==(CountedPtr<T> rhs) const;
    bool operator!=(CountedPtr<T> rhs) const;

    bool operator==(T* rhs);
    bool operator!=(T* rhs);

    T* get();
    int use_count();

    void decrease_count();
    void increase_count();

private:
    T* ptr;
    int* count;

};

#include "counted_ptr.tcc"
