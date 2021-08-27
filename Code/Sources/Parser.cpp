#include "../Headers/Parser.hpp"

//#include <iostream>
#include <cassert>
#include <sstream>
#include <cctype>

#include "../Headers/Lexer.hpp"

Operator ToOperator(char c) {

    //std::cout << std::endl << c << ' ' << std::boolalpha << IsOperator(c);
    //assert(IsOperator(c) && "Can't convert invalid char to operator");

    switch (c) {

        case '+':
        return Operator::ADD;
        break;

        case '-':
        return Operator::SUB;
        break;

        default:
        break;

    }

}

Tokens GetTokensFromExpression(std::string expression) {

    expression = RemoveSpaces(expression);

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

            t.numbers.push_back(n);
            temp.clear();

            t.operators.push_back(ToOperator(expression[i]));

        }

    }

    return t;
    
}

int Calculate(const Tokens &t) {

    unsigned int result{t.numbers[0]};
    for (std::size_t i{0}; i < t.numbers.size()-1; i++) {

        switch (t.operators[i]) {

            case Operator::ADD:
            result += t.numbers[i+1];
            break;

            case Operator::SUB:
            result -= t.numbers[i+1];
            break;

        }

    }

    return result;

}