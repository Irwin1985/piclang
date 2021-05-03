//
// Created by irwin on 03/05/2021.
//

#ifndef PICLANG_TOKENIZER_H
#define PICLANG_TOKENIZER_H
#include <list>
#include "token.h"

namespace pic {
    class Tokenizer {
    public:
        std::string expression = "";
        int currentCharPosition = 0;
        char Look;

        void Init();
        void GetChar();
        bool IsOp(char chr);
        std::string FindOpType(char chr);
        std::list<Token> Tokenize(std::string source);
    };
}

#endif //PICLANG_TOKENIZER_H
