//
// Created by irwin on 02/05/2021.
//

#ifndef PICLANG_CALCULATOR_H
#define PICLANG_CALCULATOR_H
#include <string>

namespace pic {
    class Calculator {
    public:
        std::string expression = "";
        int currentCharPosition = 0;
        char Look = '\0';
        Calculator(){}

        void GetChar();
    };
}

#endif //PICLANG_CALCULATOR_H
