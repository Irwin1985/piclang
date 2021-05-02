#include "header/calculator.h"

#include <iostream>

int main() {
    pic::Calculator calc;
    calc.expression = "1+9";
    calc.Init();
    std::cout << calc.ArithmeticExpression() << std::endl;

    return 0;
}
