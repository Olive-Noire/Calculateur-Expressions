#ifndef DEF_PARSER_HPP
#define DEF_PARSER_HPP

#include <string>
#include <vector>

using Tokens = std::vector<unsigned int>;

Tokens GetTokensFromExpression(const std::string&);
unsigned int Calculate(const Tokens&);

#endif // DEF_PARSER_HPP