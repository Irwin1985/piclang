#include "header/tokenizer.h"
#include "header/calculator.h"

#include <iostream>
#include "header/prettyprint.h"

int main() {
    std::string expression = "((853+92*5)*10-20/2+771)";
    expression += " ";

    // create the Calculator instance
    pic::Calculator calc;
    // create the Tokenizer instance
    pic::Tokenizer tokenizer;

    std::cout << "Expression: " << expression << std::endl;
    std::cout << "---------------------\n";
    calc.tokens = tokenizer.Tokenize(expression);
    pic::PrettyPrint(calc.tokens);
    std::cout << "---------------------\n";
    std::cout << "Expression result: " << calc.ArithmeticExpression() << std::endl;

    return 0;
}
