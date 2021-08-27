#include "../Headers/Parser.hpp"

#include <stdexcept>
#include <iostream>
#include <cassert>
#include <sstream>
#include <cctype>

#include "../Headers/Lexer.hpp"

Operator ToOperator(char c) {

    assert(IsOperator(c) && "Can't convert invalid char to operator");

    switch (c) {

        case '+':
        return Operator::ADD;
        break;

        case '-':
        return Operator::SUB;
        break;

        case '*':
        return Operator::MUL;
        break;

        case '/':
        return Operator::DIV;
        break;

        case '%':
        return Operator::MOD;
        break;

        case '^':
        return Operator::EXP;
        break;

        default:
        return Operator{0};
        break;

    }

}

Tokens GetTokensFromExpression(std::string expression) {

    expression = RemoveSpaces(expression);

    if (ExpressionSyntax(expression)) {

        Tokens t;

        if (expression.size() == 1) {

            if (IsNumber(expression)) {

                unsigned int n;
                std::istringstream{expression} >> n;

                t.numbers.push_back(n);

            } else {

                throw std::runtime_error{"Token Error : no recognised"};

            }
            
        } else {

            std::string temp{expression[0]};
            for (std::size_t i{1}; i < expression.size(); i++) {

                if (std::isdigit(expression[i]) && i < expression.size()-1) {

                    temp.push_back(expression[i]);

                } else {

                    if (i == expression.size()-1) {
                
                        temp.push_back(expression[i]);

                    } else {

                        t.operators.push_back(ToOperator(expression[i]));

                    }

                    if (IsNumber(temp)) {

                        unsigned int n;
                        std::istringstream{temp} >> n;

                        t.numbers.push_back(n);
                        temp.clear();

                    } else {
                        
                        throw std::runtime_error{"Token Error : no recognised"};

                    }

                }

            }

        }

        return t;

    } else {

        throw std::runtime_error{"Syntax Error"};

    }
    
}

int Calculate(Tokens t) {

    if (t.numbers.size() == 1) {
        
        return t.numbers[0];

    }

    for (std::size_t i{0}; i < t.numbers.size()-1; i++) {

        switch (t.operators[i]) {

            case Operator::EXP:

            if (t.numbers[i+1] == 0) {

                t.numbers[i] = 1;

            } else if (t.numbers[i+1] > 1) {

                int temp{static_cast<int>(t.numbers[i])};
                for (std::size_t j{1}; j < t.numbers[i+1]; j++) t.numbers[i] *= temp;

            }

            t.numbers.erase(t.numbers.begin()+i+1);
            t.operators.erase(t.operators.begin()+i);

            break;

            default:
            break;

        }

    }
    
    for (std::size_t i{0}; i < t.numbers.size()-1; i++) {

        switch (t.operators[i]) {

            case Operator::MUL:

            t.numbers[i] *= t.numbers[i+1];

            t.numbers.erase(t.numbers.begin()+i+1);
            t.operators.erase(t.operators.begin()+i);

            break;

            case Operator::DIV:

            t.numbers[i] /= t.numbers[i+1];

            t.numbers.erase(t.numbers.begin()+i+1);
            t.operators.erase(t.operators.begin()+i);

            break;

            case Operator::MOD:

            t.numbers[i] %= t.numbers[i+1];

            t.numbers.erase(t.numbers.begin()+i+1);
            t.operators.erase(t.operators.begin()+i);

            break;

            default:
            break;

        }

    }

    int result{static_cast<int>(t.numbers[0])};

    for (std::size_t i{0}; i < t.numbers.size()-1; i++) {

        switch (t.operators[i]) {

            case Operator::ADD:
            result += t.numbers[i+1];
            break;

            case Operator::SUB:
            result -= t.numbers[i+1];
            break;

            default:
            break;

        }

    }

    return result;

}