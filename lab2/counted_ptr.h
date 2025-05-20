#pragma once

template<typename T>
class CountedPtr
{
public:

    CountedPtr(T* ptr);
    CountedPtr();
    CountedPtr(CountedPtr<T> const& copied_ptr);
    ~CountedPtr();
    CountedPtr(CountedPtr<T>&& moved_ptr);

    void decrease_count();
    void increase_count();

private:
    T* ptr;
    int* count;

};
