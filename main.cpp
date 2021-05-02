#include "header/calculator.h"

#include <iostream>

int main() {
    pic::Calculator calc;
    calc.expression = "(9*3-1+8)*5-7";
    std::cout << "Expression: " << calc.expression << std::endl;
    calc.Init();
    int result = calc.ArithmeticExpression();
    std::cout << "Calculation Result: " << result << std::endl;

    return 0;
}
