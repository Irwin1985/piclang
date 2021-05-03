//
// Created by irwin on 03/05/2021.
//
#include <string>
#include "../header/token.h"
#include "../header/util.h"

namespace pic {
    std::string Token::toString() {
        return "Type: " + GetType(type) + " Text: " + text;
    }
}

