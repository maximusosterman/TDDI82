#ifndef NODE_H_
#define NODE_H_

#include "counted_ptr.h"

#include <vector>

template <typename T>
class Node
{
public:

    Node(T value = 0);

    void insert(CountedPtr<Node<T>> node);
    void remove(CountedPtr<Node<T>> node);

    typename std::vector<CountedPtr<Node<T>>>::const_iterator begin() const;
    typename std::vector<CountedPtr<Node<T>>>::const_iterator end() const;

public:

    T value { };

private:

    std::vector<CountedPtr<Node<T>>> neighbours { };

};

template <typename T>
std::vector<CountedPtr<Node<T>>> get_all_nodes(CountedPtr<Node<T>> root);



#include "node.tcc"

#endif
