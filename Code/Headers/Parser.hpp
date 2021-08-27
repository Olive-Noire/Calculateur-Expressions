#ifndef DEF_PARSER_HPP
#define DEF_PARSER_HPP

#include <string>
#include <vector>

enum class Operator {ADD = 0, SUB};

struct Tokens {

    public:

    std::vector<unsigned int> numbers;
    std::vector<Operator> operators;

};

Operator ToOperator(char);

Tokens GetTokensFromExpression(std::string);
int Calculate(const Tokens&);

#endif // DEF_PARSER_HPP