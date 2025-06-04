#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename Container>
class Cycle
{
public:

    using value_type = typename Container::value_type;

    Cycle(Container& container)
        : container {container}
    {}

    int size() const
    {
        return container.size();
    }

    value_type at(int index) const
    {
        if (index < 0)
        {
            throw std::out_of_range("Index out of range!");
        }

        return container[index % container.size()];
    }

    value_type& at(int index)
    {
        if (index < 0)
        {
            throw std::out_of_range("Index out of range!");
        }

        return container[index % container.size()];
    }

private:
    Container& container;

};

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

TEST_CASE("int vector") {
  vector<int> v {1, 2, 3, 4};
  Cycle<vector<int>> c {v};

  for (int i{0}; i < v.size(); ++i)
  {
    CHECK (c.at(i) == v.at(i));
    CHECK (c.at(i + v.size()) == v.at(i));
    CHECK (c.at(i + 2 * v.size()) == v.at(i));
  }

  c.at(0) = 5;
  CHECK(v.at(0) == 5);

  CHECK_THROWS(v.at(-1));
}

TEST_CASE("string deque") {
  deque<string> d {"programmering", "kul", "C++"};
  Cycle<deque<string>> const c {d};
  for (int i{0}; i < d.size(); ++i)
  {
    CHECK (c.at(i) == d.at(i));
    CHECK (c.at(i + d.size()) == d.at(i));
    CHECK (c.at(i + 2 * d.size()) == d.at(i));
  }
}
