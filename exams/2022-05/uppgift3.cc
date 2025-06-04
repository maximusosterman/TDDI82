#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " TEXT [ARGUMENTS...]\n";
        return 1;
    }

    std::string filename = argv[1];
    std::fstream fs;

    fs.open(filename);

    std::vector<std::string> text
    {
        std::istream_iterator<std::string>(fs),
        std::istream_iterator<std::string>()
    };

    std::vector<std::string> arguments{};
    std::string str_to_find {};

    for(int i {2}; i < argc; i++)
    {
        arguments.push_back(argv[i]);

        bool changed = false;
        
        for_each(text.begin(), text.end(),
        [&arguments, &str_to_find, &i, &changed](std::string & word)
        {
            str_to_find = '#' + std::to_string(i-2);
            if (word == str_to_find)
            {
                word = arguments[i-2];
                changed = true;
            }
        });

        if (!changed)
        {
            throw std::logic_error("No word to replace with " + arguments[i-2]);
        }

    }

    std::for_each(text.begin(), text.end(), 
    [] (std::string const& word)
    {
        std::cout << word << " ";
    });
    
    // for (auto word : text)
    // {
    //     std::cout << word << " ";
    // }

}