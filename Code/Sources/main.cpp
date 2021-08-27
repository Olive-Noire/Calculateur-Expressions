#include <iostream>
#include <limits>

#include "../Headers/Parser.hpp"

int main() {

    std::cout << "Entrez expression : ";

    std::string input;
    std::getline(std::cin, input);

    std::cout << Calculate(GetTokensFromExpression(input));

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;

}

// Commands : g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Expression solver" -std=c++17 -O3 -g -Wall -Wextra -pedantic-errors