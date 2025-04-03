#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void add_to_vector(std::vector<int>& container)
{
    int input_int {};
    
    while (std::cin >> input_int)
    {
        container.push_back(input_int);
    }
}

void print_vector(std::vector<int>& container)
{   
    std::cout << std::endl;

    for (int n : container)
    {
        std::cout << n << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> container{};
    int n {};
    std::cin >> n;

    add_to_vector(container);
    
    std::sort(container.begin(), container.end(),
                [n](int x, int y)
                {
                    return abs(x - n) < abs(y - n);
                });

    print_vector(container);
    
    return 0;
}