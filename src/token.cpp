//
// Created by irwin on 03/05/2021.
//
#include <string>
#include "../header/token.h"

namespace pic {
    std::string Token::toString() {
        return "Type: " + type + " Text: " + text;
    }
}

