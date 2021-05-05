//
// Created by irwin on 04/05/2021.
//

#ifndef PICLANG_NODE_H
#define PICLANG_NODE_H
#include "token.h"

namespace pic {
    enum astType {
        AST_BINOP,
        AST_NUMBER,
        AST_BOOLEAN,
    };
    /*
     * Node base class
     * */
    class Node {
    public:
        ~Node() {};
        virtual astType Type() = 0;
    };
    /**
     * Binary Operation Node class
     */
    class BinOpNode : public Node {
    public:
        Node* left;
        TokenType ope;
        Node* right;

        BinOpNode(Node* left, TokenType ope, Node* right) {
            this->left = left;
            this->ope = ope;
            this->right = right;
        }
        astType Type() {return AST_BINOP; }

        ~BinOpNode() {
            delete this->left;
            delete this->right;
        }
    };
    /**
     * Number Node class
     */
    class NumberNode : public Node {
    public:
        double value = 0.00;
        NumberNode()= default;

        explicit NumberNode(double value) {
            this->value = value;
        }
        astType Type() { return AST_NUMBER; }
    };
    /**
     * Boolean Node class.
     */
    class BooleanNode : public Node {
    public:
        bool value;
        BooleanNode() = default;
        BooleanNode(bool value) {
            this->value = value;
        }
        astType Type() { return AST_BOOLEAN; }
    };
}

#endif //PICLANG_NODE_H
