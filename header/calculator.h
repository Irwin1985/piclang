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
        int currentTokenPosition = 0;
        std::list<Token> tokens;

        Calculator(){}

        Token GetToken(int offset);
        Token CurrentToken();
        Token NextToken();
        void EatToken(int offset);
        Token MatchAndEat(TokenType type);
        int Multiply();
        int Divide();
        int Add();
        int Subtract();
        int Term();
        int Factor();
        int ArithmeticExpression();
        bool Relation();
        bool BooleanFactor();
        bool BooleanTerm();
        bool BooleanExpression();
        bool Expression();
        bool Equal(int leftExpressionResult);
        bool Less(int leftExpressionResult);
        bool LessEqual(int leftExpressionResult);
        bool Greater(int leftExpressionResult);
        bool GreaterEqual(int leftExpressionResult);
    };
}

#endif //PICLANG_CALCULATOR_H
