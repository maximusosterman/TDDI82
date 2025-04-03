#include <iostream>

int main(int argc, char* argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    for (const auto& arg : arguments)
    {
        std::cout << arg << std::endl;
    }

    return 0;
}
