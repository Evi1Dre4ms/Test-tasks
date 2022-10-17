#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

std::string convert(std::string&& s)
{
    // string to lower case
    for (auto& ch : s) 
        ch = std::tolower(ch);

    std::unordered_map<char, unsigned int> rv;
    for (const auto& ch : s)
        ++rv[ch];

    for (auto& ch : s)
    {
        auto it = rv.find(ch);

        if (it != rv.end()) 
            it->second > 1 ? ch = ')' : ch = '(';
    }

    return s;
}

int main()
{
    std::cout << convert("din")     << std::endl;
    std::cout << convert("recede")  << std::endl;
    std::cout << convert("Success") << std::endl;
    std::cout << convert("(( @")    << std::endl;
}