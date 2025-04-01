#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

int main ()
{

    std::map<std::string, int> words {};
    std::string input_word {};
    

    while (std::cin >> input_word)
    {
        words[input_word] += 1;
    }


    for ( const auto& [word, count]: words)
    {
        std::cout << word << " : " << count << std::endl;;
    }

    return 0;
}