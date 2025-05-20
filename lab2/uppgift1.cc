#include "counted_ptr.h"
#include "counted_ptr.tcc"

#include <iostream>
#include <cassert>
#include <string>


//Chat gpt wrote the tests
struct Dummy {
    int x;
    void hello() const { std::cout << "Hello, I am " << x << "\n"; }
};

void basic_construction_test() {
    CountedPtr<int> a{new int{10}};
    assert(*a == 10);
    assert(a.use_count() == 1);
}

void copy_constructor_test() {
    std::cout << "Copy end test started \n";
    CountedPtr<int> a{new int{5}};
    CountedPtr<int> b{a};
    assert(a.use_count() == 2);
    assert(b.use_count() == 2);
    assert(*a == *b);
    std::cout << "Copy end test ended \n";
}

void copy_assignment_test() {
    std::cout << "Copy assign test started \n";
    CountedPtr<int> a{new int{7}};
    CountedPtr<int> b;
    b = a;
    assert(a.use_count() == 2);
    assert(b.use_count() == 2);
    assert(*a == *b);
    std::cout << "Copy assign test ended \n";
}

void move_constructor_test() {
    std::cout << "Moved const test started \n";
    CountedPtr<int> a{new int{123}};
    int* raw = a.get();
    CountedPtr<int> b{std::move(a)};
    assert(b.get() == raw);
    assert(a.get() == nullptr);
    assert(b.use_count() == 1);
    std::cout << "Moved const test complete \n";

}

void move_assignment_test() {
    std::cout << "Move assign test started \n";
    CountedPtr<int> a{new int{456}};
    int* raw = a.get();
    CountedPtr<int> b;
    b = std::move(a);
    assert(b.get() == raw);
    assert(a.get() == nullptr);
    assert(b.use_count() == 1);
    std::cout << "Move assign test end \n";
}

void nullptr_assignment_test() {
    std::cout << "nullptr assignment test start \n";
    CountedPtr<int> a{new int{999}};
    a = nullptr;
    assert(a.get() == nullptr);
    assert(a.use_count() == 0);
    std::cout << "nullptr assignment test end \n";
}

void dereference_test() {
    std::cout << "Dereference test start \n";
    CountedPtr<Dummy> p{new Dummy{42}};
    assert(p->x == 42);
    assert((*p).x == 42);
    std::cout << "Dereference test end \n";
}

void comparison_test() {
    std::cout << "Comparision test start \n";
    CountedPtr<int> a{new int{1}};
    CountedPtr<int> b{a};
    CountedPtr<int> c{new int{1}};
    std::cout << "Before \n";
    assert(a == b);
    std::cout << "After \n";
    assert(a != c);
    assert(a == a.get());
    assert(c != a.get());
    std::cout << "Comparision test end \n";
}

void get_and_use_count_test() {
    CountedPtr<std::string> p{new std::string{"hej"}};
    std::string* raw = p.get();
    assert(*raw == "hej");
    assert(p.use_count() == 1);
}

int main() {
    basic_construction_test();
    copy_constructor_test();
    copy_assignment_test();
    move_constructor_test();
    move_assignment_test();
    nullptr_assignment_test();
    dereference_test();
    comparison_test();
    get_and_use_count_test();

    std::cout << "✅ Alla tester för uppgift 1 passerade!\n";

    return 0;
}
