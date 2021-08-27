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

    if (noSpace.empty() || !std::isdigit(noSpace[0])) {
        
        return false;

    } else {

        for (std::size_t i{0}; i < noSpace.size(); i++) {

            if (!std::isdigit(noSpace[i])) {

                if (noSpace[i] == '+') {

                    // if dound "++" in string
                    if (i > 0 && noSpace[i-1] == '+') return false;
                    if (i < noSpace.size()-1 && noSpace[i+1] == '+') return false;

                }

            }

        }

        return true;

    }

}