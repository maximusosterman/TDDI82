#include "node.h"

#include <iostream>

CountedPtr<Node<std::string>> create_example()
{
    CountedPtr<Node<std::string>> n0 { new Node<std::string>{"0"} };
    CountedPtr<Node<std::string>> n1 { new Node<std::string>{"1"} };
    CountedPtr<Node<std::string>> n2 { new Node<std::string>{"2"} };
    CountedPtr<Node<std::string>> n3 { new Node<std::string>{"3"} };
    CountedPtr<Node<std::string>> n4 { new Node<std::string>{"4"} };
    CountedPtr<Node<std::string>> n5 { new Node<std::string>{"5"} };

    n0->insert(n1);
    n0->insert(n2);
    n1->insert(n5);
    n2->insert(n3);
    n2->insert(n4);
    n3->insert(n4);
    n3->insert(n5);

    return n0;
}

template <typename T>
void print_nodes(std::vector<CountedPtr<Node<T>>> nodes)
{
    for (CountedPtr<Node<T>> node : nodes)
    {
        std::cout << node.get()->value << " ";
    }
    std::cout << std::endl;
}

int main()
{
    CountedPtr<Node<std::string>> root { create_example() };
    std::vector<CountedPtr<Node<std::string>>> nodes { get_all_nodes(root) };

    std::cout << "After insertions: " << std::endl;
    print_nodes(nodes);

    root->remove(nodes[2]);

    nodes = get_all_nodes(root);

    std::cout << "After removal: " << std::endl;
    print_nodes(nodes);
}
