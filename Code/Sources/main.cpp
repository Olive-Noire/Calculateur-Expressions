#include <iostream>
#include <limits>

#include "../Headers/Parser.hpp"
#include "../Headers/Lexer.hpp"

int main() {

    std::string input;

    while (RemoveSpaces(input) != "quit") {

        std::cout << "> ";
        std::getline(std::cin, input);

        try {

            std::cout << Calculate(GetTokensFromExpression(input));

        } catch (const std::exception &e) {

            std::cout << e.what();

        }

        std::cout << std::endl;

    }

    return 0;

}

// Commands : g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Expression solver" -std=c++17 -O3 -g -Wall -Wextra -pedantic-errors