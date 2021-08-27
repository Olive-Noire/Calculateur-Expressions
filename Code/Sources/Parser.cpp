#include "../Headers/Parser.hpp"

#include <cassert>
#include <sstream>
#include <cctype>

#include "../Headers/Lexer.hpp"

Tokens GetTokensFromExpression(const std::string &expression) {

    assert(ExpressionSyntax(expression) && "Syntax Error expression");

    Tokens t;

    std::string temp{expression[0]};
    for (std::size_t i{1}; i < expression.size(); i++) {

        if (std::isdigit(expression[i]) && i < expression.size()-1) {

            temp.push_back(expression[i]);

        } else {

            if (i == expression.size()-1) temp.push_back(expression[i]);

            assert(IsNumber(temp) && "Token Error no recognised");

            unsigned int n;
            std::istringstream{temp} >> n;

            t.push_back(n);
            temp.clear();

        }

    }

    return t;
    
}

unsigned int Calculate(const Tokens &t) {

    unsigned int result{0};
    for (unsigned int i : t) result += i;

    return result;

}