#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <sstream>

std::ifstream init_file(std::string const &filename)
{
    if (!std::filesystem::exists(filename))
    {
        throw std::runtime_error("File does not exists!");
    }
    std::ifstream file(filename);

    return file;
}

std::map<std::string, int> convert_to_map(std::ifstream const &file)
{
    std::map<std::string, int> words {};

    words.insert()

    //words.insert(file.begin(), file.end(), file.getline(words, file, " "));

    return words;

}

void frequency(std::ifstream const &file)
{
    std::map<std::string, int> words { convert_to_map(file) };

    for ( const auto& [word, count]: words)
    {
        std::cout << word << " : " << count << std::endl;;
    }

}

void print(std::ifstream const &file)
{
    std::cout << file.rdbuf();
}

int main(int argc, char* argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);
    std::string filename { arguments[0] };

    std::ifstream file { init_file(filename) };

    for (std::string arg : arguments)
    {
        if (arg == "--print")
        {
            print(file);
        }

        else if (arg == "--frequency")
        {
            //frequency(file);
        }
    }





    return 0;
}
