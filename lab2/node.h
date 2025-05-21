#ifndef NODE_H_
#define NODE_H_

#include "counted_ptr.h"

#include <vector>

class Node
{
public:

    Node(int value = 0);

    void insert(CountedPtr<Node> node);
    void remove(CountedPtr<Node> node);

    std::vector<CountedPtr<Node>>::const_iterator begin() const;
    std::vector<CountedPtr<Node>>::const_iterator end() const;

public:

    int value { };

private:

    std::vector<CountedPtr<Node>> neighbours { };

};

std::vector<Node*> get_all_nodes(CountedPtr<Node> root);


#endif
