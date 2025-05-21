#include <algorithm>
#include <queue>
#include <set>

template <typename T>
Node<T>::Node(T value)
    : value { value }
{
}

template <typename T>
void Node<T>::insert(CountedPtr<Node<T>> node)
{
    auto it = std::find(neighbours.begin(), neighbours.end(), node);

    // det får inte finnas dubletter av länkar
    if (it == neighbours.end())
    {
        neighbours.push_back(node);
    }
}
template <typename T>
void Node<T>::remove(CountedPtr<Node<T>> node)
{
    // om länken finns: ta bort den, annars: gör ingenting
    auto it = std::remove(neighbours.begin(), neighbours.end(), node);
    neighbours.erase(it, neighbours.end());
}

template <typename T>
typename std::vector<CountedPtr<Node<T>>>::const_iterator Node<T>::begin() const
{
    return neighbours.cbegin();
}


template <typename T>
typename std::vector<CountedPtr<Node<T>>>::const_iterator Node<T>::end() const
{
    return neighbours.cend();
}


template <typename T>
std::vector<CountedPtr<Node<T>>> get_all_nodes(CountedPtr<Node<T>> root)
{
    // Denna funktion går igenom alla noder och lägger in dem i `nodes` vektorn.
    // Notera: för att detta ska gå att göra så måste den hålla koll på vilka
    // noder som redan har besökts eftersom att flera noder kan länka till samma
    // nod.
    //
    // Om den inte håller koll på detta finns det en risk, i värsta fall, att
    // funktionen hamnar i en evig loop och, i bästa fall, att funktionen
    // producerar dubletter i resultatet.
    //
    // Detta löser funktionen genom att ha en std::set som håller koll på vilka
    // noder som redan har besökts, och en std::vector håller koll på vilka noder
    // som ska besökas härnäst.

    std::vector<CountedPtr<Node<T>>> nodes { };

    // Notera att std::set kräver att datatypen går att jämföra med operator<
    // (vilket counted_ptr inte har), så här måste vi använda vanliga pekare fortfarande.

    std::set<Node<T>*> visited { };
    std::queue<CountedPtr<Node<T>>> to_visit { };

    to_visit.push(root);
    while (!to_visit.empty())
    {
        CountedPtr<Node<T>> node { to_visit.front() };
        to_visit.pop(); // nu blir noden besökt, så den tas bort

        if (visited.count(node.get()) == 0)
        {
            visited.insert(node.get());
            nodes.push_back(node);

            // vi lägger till alla grannar till `to_visit`
            for (const CountedPtr<Node<T>>& next_ptr : *node)
            {
                to_visit.push(next_ptr);
            }
        }
    }

    return nodes;
}
