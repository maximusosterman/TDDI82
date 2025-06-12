#pragma once

/*Komplettering: Funktioner som är konstanta ska innebära att man inte kan ändra på datan pekar på. 

Det ska finnas två varianter av ´operator*´, ´operator->´ och ´get()´ 

en för när pekaren är konstant och en när den inte är det. 

och det är bara med hjälp av den icke-konstanta varianten som användaren får ändra på den underliggande datan.*/

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
    const T& operator*() const;
    const T* operator->() const;
    T& operator*();
    T* operator->();
    bool operator==(CountedPtr<T> rhs) const;
    bool operator!=(CountedPtr<T> rhs) const;
    


    bool operator==(T* rhs);
    bool operator!=(T* rhs);

    const T* get() const;
    T* get();
    int use_count();

    void decrease_count();
    void increase_count();

private:
    T* ptr;
    int* count;

};

#include "counted_ptr.tcc"
