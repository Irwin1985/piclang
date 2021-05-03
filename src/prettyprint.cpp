//
// Created by irwin on 03/05/2021.
//
#include <iostream>
#include "../header/prettyprint.h"

namespace pic {
    void PrettyPrint(std::list<Token> tokens) {
        int numberCount = 0;
        int opCount = 0;

        for (pic::Token token : tokens) {
            if (token.type == "NUMBER") {
                std::cout << "Number....: " << token.text << std::endl;
                numberCount += 1;
            } else {
                std::cout << "Operator..: " << token.type << std::endl;
                opCount += 1;
            }
        }
        std::cout << "You have got " << numberCount << " different number and " << opCount << " operators.\n";
    }
}

