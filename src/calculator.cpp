//
// Created by irwin on 02/05/2021.
//

#include "../header/calculator.h"
#include <iostream>

namespace pic {
    bool Calculator::IsDigit(char chr) {
        return '0' <= chr && chr <= '9';
    }
    void Calculator::GetChar() {
        if (currentCharPosition < expression.size()){
            Look = expression[currentCharPosition];
        }
        currentCharPosition += 1;
    }

    int Calculator::GetNum() {
        int number = 0;
        std::string tempStr = "";
        if (!IsDigit(Look)) {
            std::cout << "Error: Numbers expected. " << std::endl;
            exit(1);
        }
        while (IsDigit(Look)) {
            tempStr = tempStr + Look;
            GetChar();
        }
        number = std::stoi(tempStr);
        return number;
    }

    void Calculator::Init() {
        GetChar();
    }

    void Calculator::MatchAndEat(char chr) {
        if (Look == chr) {
            GetChar();
        } else{
            std::cout << "Error: Unexpected character.";
            std::exit(1);
        }
    }

    int Calculator::Term() {
        int result = Factor();
        while ( Look == '*' || Look == '/' ) {
            switch (Look) {
                case '*':
                    result = result * Multiply();
                    break;
                case '/':
                    result = result / Divide();
                    break;
            }
        }
        return result;
    }

    int Calculator::Add() {
        MatchAndEat('+');
        return Term();
    }

    int Calculator::Subtract() {
        MatchAndEat('-');
        return Term();
    }

    int Calculator::ArithmeticExpression() {
        int result = Term();
        while ( Look == '+' || Look == '-' ) {
            switch (Look) {
                case '+':
                    result = result + Add();
                    break;
                case '-':
                    result = result - Subtract();
                    break;
            }
        }

        return result;
    }

    int Calculator::Factor() {
        int result = 0;
        if (Look == '(') {
            MatchAndEat('(');
            result = ArithmeticExpression();
            MatchAndEat(')');
        } else {
            result = GetNum();
        }
        return result;
    }

    int Calculator::Multiply() {
        MatchAndEat('*');
        return Factor();
    }

    int Calculator::Divide() {
        MatchAndEat('/');
        return Factor();
    }
}

