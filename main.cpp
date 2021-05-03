#include "header/tokenizer.h"
#include "header/calculator.h"

#include <iostream>
#include "header/util.h"

int main() {
    std::string expression = "5<7";
    expression += " ";

    // create the Calculator instance
    pic::Calculator calc;
    // create the Tokenizer instance
    pic::Tokenizer tokenizer;

    std::cout << "Expression: " << expression << std::endl;
    std::cout << "---------------------\n";
    calc.tokens = pic::Tokenizer::Tokenize(expression);
    pic::PrettyPrint(calc.tokens);
    std::cout << "---------------------\n";

    std::cout << "Expression result: " << calc.Expression() << std::endl;

    return 0;
}
