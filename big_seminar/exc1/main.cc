#include <iostream>
#include <set>
#include <iomanip>

int main()
{
    std::set<int> container{};
    int input_int {};

    while (std::cin >> input_int)
    {
        container.insert(input_int);
    }

    std::cout << std::endl;

    for (int n : container)
    {
        std::cout << n << " ";
    }

    std::cout << std::endl;

    return 0;
}
