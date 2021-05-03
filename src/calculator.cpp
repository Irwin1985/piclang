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
            if (CurrentToken().type == MULTIPLY) {
                result = result * Multiply();
            }
            else if ( CurrentToken().type == DIVIDE) {
                result = result / Divide();
            }
        }
        return result;
    }

    int Calculator::ArithmeticExpression() {
        int result = Term();
        while ( CurrentToken().type == ADD || CurrentToken().type == SUBTRACT ) {
            if (CurrentToken().type == ADD) {
                result = result + Add();
            }
            else if (CurrentToken().type == SUBTRACT) {
                result = result - Subtract();
            }
        }
        return result;
    }
}