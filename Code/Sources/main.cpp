#include <iostream>

#include "../Headers/Lexer.hpp"

int main() {

    std::cout << std::boolalpha << ExpressionSyntax("+");
    std::cin.get();

    return 0;

}

// Commands : g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Expression solver" -std=c++17 -O3 -g -Wall -Wextra -pedantic-errors