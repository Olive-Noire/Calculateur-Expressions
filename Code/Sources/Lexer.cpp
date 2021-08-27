#include "../Headers/Lexer.hpp"

#include <cctype>

bool IsNumber(const std::string &s) {

    for (char c : s) {

        if (!std::isdigit(c)) return false;

    }

    return true;

}

bool ExpressionSyntax(const std::string &expression) {

    std::string noSpace;
    for (char c : expression) {

        if (!std::isspace(c)) noSpace.push_back(c);

    }

    if (noSpace.empty()) {
        
        return false;

    } else {

        for (char c : noSpace) {

            if (!std::isdigit(c) && c != '+') return false;

        }

        return true;

    }

}