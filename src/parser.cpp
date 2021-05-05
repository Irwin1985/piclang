//
// Created by irwin on 02/05/2021.
//

#include "../header/parser.h"
#include <iostream>

namespace pic {

    Node* Parser::Parse() {
        return Expression();
    }

    Token Parser::GetToken(int offset) {
        if (currentTokenPosition + offset >= tokens.size()) {
            return Token("", END);
        }
        // get an element from list
        auto l_front = tokens.begin(); // go top of the list
        std::advance(l_front, currentTokenPosition + offset); // call advance function.

        return *l_front; // indirect the pointer
    }

    Token Parser::CurrentToken() {
        return GetToken(0);
    }

    void Parser::EatToken(int offset) {
        currentTokenPosition += offset;
    }

    Token Parser::MatchAndEat(TokenType type) {
        Token token = CurrentToken();
        if (CurrentToken().type != type) {
            std::cout << "Saw " << token.type << " but " << type << " expected.\n";
            std::exit(1);
        }
        EatToken(1); // move the currentTokenPosition forward
        return token; // return the just eaten token.
    }

    Node* Parser::Factor() {
        Node* result = nullptr;
        if (CurrentToken().type == LEFT_PAREN) {
            MatchAndEat(LEFT_PAREN);
            result = ArithmeticExpression();
            MatchAndEat(RIGHT_PAREN);
        }
        else if (CurrentToken().type == NUMBER) {
            result = new NumberNode(std::stod(CurrentToken().text));
            MatchAndEat(NUMBER);
        }
        return result;
    }

    Node* Parser::Term() {
        Node* result = Factor();
        while ( CurrentToken().type == MULTIPLY || CurrentToken().type == DIVIDE ) {
            TokenType type = CurrentToken().type;
            MatchAndEat(type);
            result = new BinOpNode(result, type, Factor());
        }
        return result;
    }

    Node* Parser::ArithmeticExpression() {
        Node* result = Term();
        while ( CurrentToken().type == ADD || CurrentToken().type == SUBTRACT ) {
            TokenType type = CurrentToken().type;
            MatchAndEat(type);
            result = new BinOpNode(result, type, Term());
        }
        return result;
    }

    Node* Parser::Less(Node* leftExpressionResult) {
        MatchAndEat(LESS);
        return new BinOpNode(leftExpressionResult, LESS, ArithmeticExpression());
    }

    Node* Parser::LessEqual(Node* leftExpressionResult) {
        MatchAndEat(LESSEQUAL);
        return new BinOpNode(leftExpressionResult, LESSEQUAL, ArithmeticExpression());
    }

    Node* Parser::Equal(Node* leftExpressionResult) {
        MatchAndEat(EQUAL);
        return new BinOpNode(leftExpressionResult, EQUAL, ArithmeticExpression());
    }

    Node* Parser::Greater(Node* leftExpressionResult) {
        MatchAndEat(GREATER);
        return new BinOpNode(leftExpressionResult, GREATER, ArithmeticExpression());
    }

    Node* Parser::GreaterEqual(Node* leftExpressionResult) {
        MatchAndEat(GREATEREQUAL);
        return new BinOpNode(leftExpressionResult, GREATEREQUAL, ArithmeticExpression());
    }

    Node* Parser::Relation() {
        Node* leftExpresionResult = ArithmeticExpression();
        Node *result = nullptr;
        TokenType type = CurrentToken().type;
        if ( type == EQUAL || type == LESS || type == LESSEQUAL || type == GREATER || type == GREATEREQUAL) {
            switch (CurrentToken().type) {
                case EQUAL:
                    result = Equal(leftExpresionResult);
                    break;
                case LESS:
                    result = Less(leftExpresionResult);
                    break;
                case LESSEQUAL:
                    result = LessEqual(leftExpresionResult);
                    break;
                case GREATER:
                    result = Greater(leftExpresionResult);
                    break;
                case GREATEREQUAL:
                    result = GreaterEqual(leftExpresionResult);
                    break;
                default:
                    break;
            }
        }
        if (result == nullptr) {
            return leftExpresionResult;
        }
        return result;
    }

    Node* Parser::BooleanFactor() {
        return Relation();
    }

    Node* Parser::BooleanTerm() {
        Node* result = BooleanFactor();

        while (CurrentToken().type == AND) {
            MatchAndEat(AND);
            result = new BinOpNode(result, AND, BooleanFactor());
        }
        return result;
    }

    Node* Parser::BooleanExpression() {
        Node* result = BooleanTerm();
        while (CurrentToken().type == OR) {
            MatchAndEat(OR);
            result = new BinOpNode(result, OR, BooleanTerm());
        }
        return result;
    }

    Node* Parser::Expression() {
        return BooleanExpression();
    }
}