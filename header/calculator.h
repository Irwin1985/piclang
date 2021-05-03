//
// Created by irwin on 02/05/2021.
//

#ifndef PICLANG_CALCULATOR_H
#define PICLANG_CALCULATOR_H
#include <string>
#include "token.h"
#include <list>

namespace pic {
    class Calculator {
    public:
        std::list<Token> tokens;
        int currentTokenPosition = 0;
        char Look = '\0';
        Calculator(){}

        Token MatchAndEat(TokenType type);
        int Term();
        int Add();
        int Subtract();
        int ArithmeticExpression();
        int Factor();
        int Multiply();
        int Divide();

        Token CurrentToken();
        Token GetToken(int offset);
        void EatToken(int offset);
    };
}

#endif //PICLANG_CALCULATOR_H
