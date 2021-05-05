//
// Created by irwin on 05/05/2021.
//

#include "../header/evaluator.h"

namespace pic {

    Obj* Evaluator::Evaluate(Node* node) {
        astType type = node->Type();
        switch (type) {
            case AST_NUMBER:
                return new NumberObj(((NumberNode*)node)->value);
            case AST_BOOLEAN:
                return ((BooleanObj*)node)->value ? TRUE : FALSE;
        }
    }
}