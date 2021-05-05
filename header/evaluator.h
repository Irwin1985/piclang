//
// Created by irwin on 05/05/2021.
//

#ifndef PICLANG_EVALUATOR_H
#define PICLANG_EVALUATOR_H
#include "object.h"
#include "node.h"

namespace pic {
    class Evaluator {
    public:
        BooleanObj* TRUE = new BooleanObj(true);
        BooleanObj* FALSE = new BooleanObj(false);

        Evaluator() = default;
        Obj* Evaluate(Node* node);
    };
}

#endif //PICLANG_EVALUATOR_H
