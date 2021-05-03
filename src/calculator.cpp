//
// Created by irwin on 02/05/2021.
//

#include "../header/calculator.h"
#include <iostream>

namespace pic {

    Token Calculator::GetToken(int offset) {
        if (currentTokenPosition + offset >= tokens.size()) {
            return Token("", END);
        }
        // get an element from list
        auto l_front = tokens.begin(); // go top of the list
        std::advance(l_front, currentTokenPosition + offset); // call advance function.

        return *l_front; // indirect the pointer
    }

    Token Calculator::CurrentToken() {
        return GetToken(0);
    }

    Token Calculator::NextToken() {
        return GetToken(1);
    }

    void Calculator::EatToken(int offset) {
        currentTokenPosition += offset;
    }

    Token Calculator::MatchAndEat(TokenType type) {
        Token token = CurrentToken();
        if (CurrentToken().type != type) {
            std::cout << "Saw " << token.type << " but " << type << " expected.\n";
            std::exit(1);
        }
        EatToken(1); // move the currentTokenPosition forward
        return token; // return the just eaten token.
    }

    int Calculator::Multiply() {
        MatchAndEat(MULTIPLY);
        return Factor();
    }

    int Calculator::Divide() {
        MatchAndEat(DIVIDE);
        return Factor();
    }

    int Calculator::Add() {
        MatchAndEat(ADD);
        return Term();
    }

    int Calculator::Subtract() {
        MatchAndEat(SUBTRACT);
        return Term();
    }

    int Calculator::Factor() {
        int result = 0;
        if (CurrentToken().type == LEFT_PAREN) {
            MatchAndEat(LEFT_PAREN);
            result = ArithmeticExpression();
            MatchAndEat(RIGHT_PAREN);
        }
        else if (CurrentToken().type == NUMBER) {
            result = std::stoi(CurrentToken().text);
            MatchAndEat(NUMBER);
        }
        return result;
    }

    int Calculator::Term() {
        int result = Factor();
        while ( CurrentToken().type == MULTIPLY || CurrentToken().type == DIVIDE ) {
            switch (CurrentToken().type) {
                case MULTIPLY:
                    result *= Multiply();
                    break;
                case DIVIDE:
                    result /= Divide();
                    break;
                default:
                    break;
            }
        }
        return result;
    }

    int Calculator::ArithmeticExpression() {
        int result = Term();
        while ( CurrentToken().type == ADD || CurrentToken().type == SUBTRACT ) {
            switch (CurrentToken().type) {
                case ADD:
                    result += Add();
                    break;
                case SUBTRACT:
                    result -= Subtract();
                    break;
                default:
                    break;
            }
        }
        return result;
    }

    bool Calculator::Less(int leftExpressionResult) {
        MatchAndEat(LESS);
        return leftExpressionResult < ArithmeticExpression();
    }

    bool Calculator::LessEqual(int leftExpressionResult) {
        MatchAndEat(LESSEQUAL);
        return leftExpressionResult <= ArithmeticExpression();
    }

    bool Calculator::Equal(int leftExpressionResult) {
        MatchAndEat(EQUAL);
        return leftExpressionResult == ArithmeticExpression();
    }

    bool Calculator::Greater(int leftExpressionResult) {
        MatchAndEat(GREATER);
        return leftExpressionResult > ArithmeticExpression();
    }

    bool Calculator::GreaterEqual(int leftExpressionResult) {
        MatchAndEat(GREATEREQUAL);
        return leftExpressionResult >= ArithmeticExpression();
    }

    bool Calculator::Relation() {
        int leftExpresionResult = ArithmeticExpression();
        bool result = false;
        TokenType type = CurrentToken().type;
        if ( type == EQUAL || type == LESS || type == LESSEQUAL || type == GREATER || type == GREATEREQUAL) {
            switch (CurrentToken().type) {
                case EQUAL:
                    result = Equal(leftExpresionResult);
                    break;
                case LESS:
                    result = Less(leftExpresionResult);
                    break;
                case LESSEQUAL:
                    result = LessEqual(leftExpresionResult);
                    break;
                case GREATER:
                    result = Greater(leftExpresionResult);
                    break;
                case GREATEREQUAL:
                    result = GreaterEqual(leftExpresionResult);
                    break;
                default:
                    break;
            }
        }
        return result;
    }

    bool Calculator::BooleanFactor() {
        return Relation();
    }

    bool Calculator::BooleanTerm() {
        bool result = BooleanFactor();

        while (CurrentToken().type == AND) {
            MatchAndEat(AND);
            result = result && BooleanFactor();
        }
        return result;
    }

    bool Calculator::BooleanExpression() {
        bool result = BooleanTerm();
        while (CurrentToken().type == OR) {
            MatchAndEat(OR);
            result = result || BooleanTerm();
        }
        return result;
    }

    bool Calculator::Expression() {
        return BooleanExpression();
    }
}