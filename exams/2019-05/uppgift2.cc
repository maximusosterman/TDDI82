#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <sstream>
#include <algorithm>


int main()
{
    std::string filename = "names.txt";
    std::fstream fs;

    fs.open(filename);

    std::map<std::string, std::vector<std::string>> tags;
    std::string line {};
    std::string name {};

    while (std::getline(fs, line))
    {
        std::istringstream iss {line};
        iss >> name;

        name.pop_back();

        std::string s {};

        while (iss >> s)
        {
            std::cout << s << "\n";
            tags[name].push_back(s);
        }

        std::sort(tags[name].begin(), tags[name].end());
    }

    for (auto [key, tags_v] : tags)
    {
        std::cout << ke•y << ": ";

        for (auto tag : tags_v)
        {
            std::cout << tag << " ";
        }
        std::cout << '\n';
    }

    std::cout << "Mata in taggar: ";
    std::vector<std::string> input
    {
        std::istream_iterator<std::string>{std::cin},
        std::istream_iterator<std::string>{}
    };

    map[key] = value;


    for (auto i : tags[input[0]])
    {
        std::cout << i << " ";
    }

    std::vector<std::string> common_names
    {
    };


    return 0;
}
