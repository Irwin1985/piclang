//
// Created by irwin on 03/05/2021.
//
#include <iostream>
#include "../header/util.h"

namespace pic {
    void PrettyPrint(const std::list<Token> &tokens) {
        int numberCount = 0;
        int opCount = 0;

        for (const auto& token : tokens) {
            if (token.type == NUMBER) {
                std::cout << "Number....: " << token.text << std::endl;
                numberCount += 1;
            } else {
                std::cout << "Operator..: " << GetType(token.type) << std::endl;
                opCount += 1;
            }
        }
        std::cout << "You have got " << numberCount << " different number and " << opCount << " operators.\n";
    }

    std::string GetType(TokenType type){
        switch (type) {
            case NUMBER:
                return "NUMBER";
            case NEWLINE:
                return "NEWLINE";
            case OPERATOR:
                return "OPERATOR";
            case END:
                return "END";
            case UNKNOWN:
                return "UNKNOWN";
            case ADD:
                return "ADD";
            case SUBTRACT:
                return "SUBTRACT";
            case MULTIPLY:
                return "MULTIPLY";
            case DIVIDE:
                return "DIVIDE";
            case LEFT_PAREN:
                return "LEFT_PAREN";
            case RIGHT_PAREN:
                return "RIGHT_PAREN";
            case LESS:
                return "LESS";
            case LESSEQUAL:
                return "LESS_EQUAL";
            case GREATER:
                return "GREATER";
            case GREATEREQUAL:
                return "GREATER_EQUAL";
            case EQUAL:
                return "EQUAL";
            case NOTEQUAL:
                return "NOT_EQUAL";
            case NOT:
                return "NOT";
            case AND:
                return "AND";
            case OR:
                return "OR";
            default:
                return "UNKNOWN";
        }
    }
}

