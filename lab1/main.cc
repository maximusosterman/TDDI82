#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>

std::vector<std::string> init_file(std::string const &filename)
{
    if (!std::filesystem::exists(filename))
    {
        throw std::runtime_error("File does not exists!");
    }

    std::ifstream ifs(filename);
    std::vector<std::string> words { //Chat.gpt helped with finding right algorithm
                std::istream_iterator<std::string>(ifs),
                std::istream_iterator<std::string>()
    };
    
    return words;
}


std::map<std::string, int> convert_to_map(std::vector<std::string> const &words)
{
    std::map<std::string, int> map_of_words{};

    std::transform(words.begin(), words.end(), std::inserter(map_of_words, map_of_words.end()),
               [&words](const std::string &s) 
               { return std::make_pair(s, std::count(words.begin(), words.end(), s)); });

    return map_of_words;

}

std::string find_longest_word(std::vector<std::string> words) 
{
    auto longest_word { std::max_element(words.begin(), words.end(),
        [](std::string const &a, std::string const &b)
    {
        return a.size() < b.size();
    })};

    if (longest_word != words.end())
    {
        return *longest_word;
    }

    return "";
}

void print_pairs(std::vector<std::pair<std::string, int>> const& pairs, std::string const &longest_word)
{
    for(auto &[word, count] : pairs)
    {
        std::cout << std::setw(longest_word.size())
                  << word
                  << ' ' 
                  << count 
                  << '\n';
    }
}

void table(std::vector<std::string> const &words)
{
    std::map<std::string, int> map_of_words = convert_to_map(words);
    std::vector<std::pair<std::string, int>> wordpairs {};

    std::copy(map_of_words.begin(), map_of_words.end(), std::back_inserter(wordpairs));

    std::string longest_word = find_longest_word(words);

    std::cout << std::fixed << std::left;

    print_pairs(wordpairs, longest_word);
}

void remove(std::vector<std::string> &words, std::string const &word_to_remove)
{
    words.erase(std::remove(words.begin(),words.end(), word_to_remove), words.end());
}


void frequency(std::vector<std::string> const &words)
{
    std::map<std::string, int> map_of_words{ convert_to_map(words) };
    std::vector<std::pair<std::string, int>> wordpairs {};

    std::copy(map_of_words.begin(), map_of_words.end(), std::back_inserter(wordpairs));
    std::sort(wordpairs.begin(), wordpairs.end(), 
    [](std::pair<std::string, int> a, std::pair<std::string, int> b)
    {
        return a.second > b.second;
    });

    std::string longest_word = find_longest_word(words);

    std::cout << std::fixed << std::right;

    print_pairs(wordpairs, longest_word);
}

void substitute(std::vector<std::string> &words, std::string const &old_word, std::string const &new_word)
{

    std::transform(words.begin(), words.end(), words.begin(),
            [&old_word, &new_word] (std::string current)
            {
                
                if (current == old_word)
                {
                    return new_word;
                }
                return current;
            });
}

std::vector<std::string> get_args(int argc, char* argv[])
{
    if (argc == 1)
    {
        throw std::runtime_error("Too few args given!!");
        
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    return arguments;
}

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
    std::vector<std::string> arguments { get_args(argc, argv )};

    std::string filename { arguments[0] };
    std::vector<std::string> words{ init_file(filename) };

    for (std::string arg : arguments)
    {

        if (arg == filename)
        {
            continue;
        }

        std::string flag {};
        std::string parameter {};

        if (arg.find('=') != std::string::npos)
        {
            flag = arg.substr(0, arg.find('='));
            parameter = arg.substr(arg.find('=')+1, arg.size());
        }

        else
        {
            flag = arg;
        }

        if (flag == "--print")
        {
            print(words);
        }

        else if (flag == "--frequency")
        {
            frequency(words);
        }
        
        else if (flag == "--table")
        {
            table(words);
        }

        else if (flag == "--remove")
        {
            remove(words, parameter);
        }

        else if (flag == "--substitute")
        {

            std::string old_word {};
            std::string new_word {};


            if (parameter.find('+') != std::string::npos)
            {
                old_word = parameter.substr(0, parameter.find('+'));
                new_word = parameter.substr(parameter.find('+')+1, parameter.size());
            }
            else
            {
                throw std::runtime_error("Too few args given for substitue flag!!");
            }

            substitute(words, old_word, new_word);

        }

        else {
            throw std::runtime_error({"Invalid flag: " + flag});
        }
    }

    return 0;
}
