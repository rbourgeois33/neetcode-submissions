//Claude's solution C++ idiomatic
#include <ranges>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        auto alnum = [](char c) { return std::isalnum(static_cast<unsigned char>(c)) != 0; };
        auto low   = [](char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c))); };

        auto v = std::views::transform(std::views::filter(s, alnum), low); //filter & lower case
        return std::ranges::equal(v, std::views::reverse(v)); // check equality
    }
};

//filter: A range adaptor that represents a view of an underlying sequence without the elements that fail to satisfy a predicate.
//transform non materialized transform
