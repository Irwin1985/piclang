//
// Created by irwin on 02/05/2021.
//

#include "../header/calculator.h"

namespace pic {
    void Calculator::GetChar() {
        if (currentCharPosition < expression.size()){
            Look = expression[currentCharPosition];
        }
        currentCharPosition += 1;
    }
}

