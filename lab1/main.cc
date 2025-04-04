#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

std::vector<std::string> init_file(std::string const &filename)
{
    if (!std::filesystem::exists(filename))
    {
        throw std::runtime_error("File does not exists!");
    }

    std::ifstream ifs(filename);
    std::vector<std::string> words {
                std::istream_iterator<std::string>(ifs),
                std::istream_iterator<std::string>()
    };
    

    return words;
}

// std::vector<std::string> get_args(int argc, char* argv[])
// {
//     std::vector<std::string> arguments(argv + 1, argv + argc);

//     if (arguments.size() == 0)
//     {
//         throw std::runtime_error("Too few arguments given!");
//     }

//     std::string filename { arguments[0] };

//     return arguments;
// }

// std::map<std::string, int> convert_to_map(std::ifstream const &file)
// {
//     std::map<std::string, int> words {};

//     words.insert()

//     //words.insert(file.begin(), file.end(), file.getline(words, file, " "));

//     return words;

// }

// void frequency(std::ifstream const &file)
// {
//     std::map<std::string, int> words { convert_to_map(file) };

//     for ( const auto& [word, count]: words)
//     {

//         std::cout << word << " : " << count << std::endl;;
//     }

// }

void print(std::vector<std::string> const &words)
{
    for (const auto& word : words)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);
    std::string filename { arguments[0] };

    std::vector<std::string> container{ init_file(filename) };

    for (std::string arg : arguments)
    {
        if (arg == "--print")
        {
            print(container);
        }

        else if (arg == "--frequency")
        {
            //frequency(file);
        }


    }





    return 0;
}
