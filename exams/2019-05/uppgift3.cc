#include <iostream>
#include <vector>
using namespace std;

// Plats för sum

template <typename container>
typename container::value_type sum(container const& c)
{
    typename container::value_type sum {};
            
    for (auto element : c)
    {
        sum += element;
    }

    return sum;
}

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("double") {
    vector<double> v {1.2,3,4.4};
    REQUIRE(Approx(sum(v)) == 8.6);
}
TEST_CASE("int") {
    vector<int> v {1,2,3,2,4,5,7};
    REQUIRE(sum(v) == 24);
}