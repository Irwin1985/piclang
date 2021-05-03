//
// Created by irwin on 03/05/2021.
//

#ifndef PICLANG_TOKENIZER_H
#define PICLANG_TOKENIZER_H
#include <list>
#include "token.h"

namespace pic {

    enum TokenState {
        TS_DEFAULT,
        TS_OPERATOR,
        TS_NUMBER,
        TS_STRING
    };

    class Tokenizer {
    public:
        static bool IsOp(char chr);
        static TokenType FindOpType(char chr);
        static std::list<Token> Tokenize(std::string source);
    };
}

#endif //PICLANG_TOKENIZER_H
