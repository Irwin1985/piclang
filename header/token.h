//
// Created by irwin on 03/05/2021.
//

#ifndef PICLANG_TOKEN_H
#define PICLANG_TOKEN_H
#include <string>

namespace pic {
    class Token {
    public:
        std::string text;
        std::string type;

        Token() {};

        Token(std::string text, std::string type) {
            this->text = text;
            this->type = type;
        }
        Token(char text, std::string type) {
            this->text = std::string(1, text);
            this->type = type;
        }
        std::string toString();
    };
}


#endif //PICLANG_TOKEN_H
