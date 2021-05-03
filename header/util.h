//
// Created by irwin on 03/05/2021.
//
#include "token.h"
#include <list>
#ifndef PICLANG_PRETTYPRINT_H
#define PICLANG_PRETTYPRINT_H

namespace pic {
    void PrettyPrint(const std::list<Token> &tokens);
    std::string GetType(TokenType type);
}

#endif //PICLANG_PRETTYPRINT_H
