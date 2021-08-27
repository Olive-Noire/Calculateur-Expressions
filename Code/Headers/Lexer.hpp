#ifndef DEF_LEXER_HPP
#define DEF_LEXER_HPP

#include <string>
#include <vector>

std::string RemoveSpaces(const std::string&);

bool IsOperator(char);
bool IsNumber(const std::string&);
bool ExpressionSyntax(std::string);

#endif // DEF_LEXER_HPP