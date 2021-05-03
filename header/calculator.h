//
// Created by irwin on 02/05/2021.
//

#ifndef PICLANG_CALCULATOR_H
#define PICLANG_CALCULATOR_H
#include <string>

namespace pic {
    class Calculator {
    public:
        std::string expression = "";
        int currentCharPosition = 0;
        int currentTokenPosition = 0;
        char Look = '\0';
        Calculator(){}

        void GetChar();
        int GetNum();
        void Init();
        void MatchAndEat(char chr);
        int Term();
        int Add();
        int Subtract();
        int ArithmeticExpression();
        int Factor();
        int Multiply();
        int Divide();
        bool IsDigit(char chr);
    };
}

#endif //PICLANG_CALCULATOR_H
