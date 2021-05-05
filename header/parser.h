//
// Created by irwin on 02/05/2021.
//

#ifndef PICLANG_PARSER_H
#define PICLANG_PARSER_H
#include <string>
#include "token.h"
#include <list>
#include "node.h"

namespace pic {
    class Parser {
    public:
        int currentTokenPosition = 0;
        std::list<Token> tokens;

        Parser(){}
        Node* Parse();
        Token GetToken(int offset);
        Token CurrentToken();
        void EatToken(int offset);
        Token MatchAndEat(TokenType type);
        Node* Term();
        Node* Factor();
        Node* ArithmeticExpression();
        Node* Relation();
        Node* BooleanFactor();
        Node* BooleanTerm();
        Node* BooleanExpression();
        Node* Expression();
        Node* Equal(Node* leftExpressionResult);
        Node* Less(Node* leftExpressionResult);
        Node* LessEqual(Node* leftExpressionResult);
        Node* Greater(Node* leftExpressionResult);
        Node* GreaterEqual(Node* leftExpressionResult);
    };
}

#endif //PICLANG_PARSER_H
