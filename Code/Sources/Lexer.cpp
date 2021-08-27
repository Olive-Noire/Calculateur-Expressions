#include "../Headers/Lexer.hpp"

#include <cctype>

std::string RemoveSpaces(const std::string &s) {

    std::string noSpaces;
    for (char c : s) {

        if (!std::isspace(c)) noSpaces.push_back(c);

    }

    return noSpaces;

}

bool IsOperator(char c) {

    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';

}

bool IsNumber(const std::string &s) {

    for (char c : s) {

        if (!std::isdigit(c)) return false;

    }

    return true;

}

bool ExpressionSyntax(std::string expression) {

    expression = RemoveSpaces(expression);

    if (expression.empty() || !std::isdigit(expression[0]) || !std::isdigit(expression.back())) {
        
        return false;

    } else {

        for (std::size_t i{0}; i < expression.size(); i++) {

            if (!std::isdigit(expression[i])) {

                if (IsOperator(expression[i])) {

                    // if dound "++" in string
                    if (i > 0 && IsOperator(expression[i+1])) return false;
                    if (i < expression.size()-1 && IsOperator(expression[i-1])) return false;

                }

            }

        }

        return true;

    }

}