#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

bool are_palindromes(string const& word1, string const& word2)
{

    if (word1.size() != word2.size())
    {
        return false;
    }

    bool result = true;
    for_each(word1.begin(), word1.end(),
    [&word2, &result] (char const &letter)
    {
        if (!(std::find(word2.begin(), word2.end(), letter) != word2.end()))
        {
            result = false;
        }
    });
    return result;
}

int main()
{
    string word {};

    cout << "Mata in ett ord: ";
    cin >> word;

    cout << "Mata in en text: ";

    words.erase(std::remove_if(words.begin(), words.end(),
                [&word](string const & other)
                {
                    return are_palindromes(word, other);
                }),
                words.end());

    copy(begin(words), end(words), ostream_iterator<string>{cout, " "});
    cout << endl;
}
