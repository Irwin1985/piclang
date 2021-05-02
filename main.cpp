#include "header/calculator.h"

#include <iostream>

int main() {
    pic::Calculator calc;
    calc.expression = "1";
    calc.GetChar();
    std::cout << calc.Look << std::endl;
    return 0;
}
