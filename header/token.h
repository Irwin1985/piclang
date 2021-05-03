//
// Created by irwin on 03/05/2021.
//

#ifndef PICLANG_TOKEN_H
#define PICLANG_TOKEN_H
#include <string>

namespace pic {

    enum TokenType {
        NUMBER,
        NEWLINE,
        OPERATOR,
        END,
        UNKNOWN,
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        LEFT_PAREN,
        RIGHT_PAREN
    };

    class Token {
    public:
        std::string text;
        TokenType type;

        Token() {};

        Token(std::string text, TokenType type) {
            this->text = text;
            this->type = type;
        }
        Token(char text, TokenType type) {
            this->text = std::string(1, text);
            this->type = type;
        }
        std::string toString();
    };
}


#endif //PICLANG_TOKEN_H
