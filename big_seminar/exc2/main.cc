#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> container{};
    int input_int {};

    while (std::cin >> input_int)
    {
        container.push_back(input_int);
    }

    std::cout << std::endl;

    int greatest_element {*std::max_element(container.begin(), container.end())};
    long int count_of_greatest {std::count(container.begin(), container.end(), greatest_element)};

    std::cout << count_of_greatest << std::endl;

    return 0;
}
