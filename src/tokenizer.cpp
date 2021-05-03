//
// Created by irwin on 03/05/2021.
//
#include <string>
#include <iostream>
#include "../header/tokenizer.h"

namespace pic {

    bool Tokenizer::IsOp(char chr) {
        auto addOp = chr == '+' || chr == '-';
        auto mulOp = chr == '*' || chr == '/';
        auto compOp = chr == '<' || chr == '>' || chr == '=';
        auto logicOp = chr == '!' || chr == '|' || chr == '&';

        return addOp || mulOp || compOp || logicOp;
    }

    TokenType Tokenizer::FindOpType(char firstOperator, char nextChar) {
        TokenType type = UNKNOWN;
        switch (firstOperator) {
            case '+':
                type = ADD;
                break;
            case '-':
                type = SUBTRACT;
                break;
            case '*':
                type = MULTIPLY;
                break;
            case '/':
                type = DIVIDE;
                break;
            case '<':
                type = LESS;
                if (nextChar == '=') type = LESSEQUAL;
                break;
            case '>':
                type = GREATER;
                if (nextChar == '=') type = GREATEREQUAL;
                break;
            case '=':
                type = ASSIGNMENT;
                if (nextChar == '=') type = EQUAL;
                break;
            case '!':
                type = NOT;
                if (nextChar == '=') type = NOTEQUAL;
                break;
            case '|':
                type = OR;
                break;
            case '&':
                type = AND;
                break;
            default:
                std::cout << "Unknown operator: " << firstOperator << std::endl;
                break;
        }
        return type;
    }

    bool Tokenizer::IsParen(char chr) {
        auto parenOp = chr == '(' || chr == ')';
        return parenOp;
    }

    TokenType Tokenizer::FindParenType(char chr) {
        TokenType type = UNKNOWN;
        switch (chr) {
            case '(':
                type = LEFT_PAREN;
                break;
            case ')':
                type = RIGHT_PAREN;
                break;
            default:
                break;
        }
        return type;
    }

    std::list<Token> Tokenizer::Tokenize(std::string source) {
        std::list<Token> tokens;

        Token token;
        std::string tokenStr;
        char firstOperator = '\0';
        TokenState state = TS_DEFAULT;

        for (int index = 0; index < source.size(); index++) {
            char chr = source[index];
            switch (state) {
                case TS_DEFAULT:
                    if (IsOp(chr)) {
                        firstOperator = chr;
                        TokenType opType = FindOpType(firstOperator, '\0');
                        token = Token(chr, opType);
                        state = TS_OPERATOR;
                    }
                    else if (isdigit(chr)) {
                        tokenStr += chr;
                        state = TS_NUMBER;
                    }
                    else if (IsParen(chr)) {
                        TokenType parenType = FindParenType(chr);
                        tokens.emplace_back(Token(chr, parenType));
                    }
                    break;
                case TS_OPERATOR:
                    if (IsOp(chr)) {
                        TokenType opType = FindOpType(firstOperator, chr);
                        std::string text = std::string(1, firstOperator) + std::string(1, chr);
                        token = Token(text, opType);
                    } else {
                        tokens.emplace_back(token);
                        state = TS_DEFAULT;
                        index -= 1;
                    }
                    break;
                case TS_NUMBER:
                    if (isdigit(chr)) {
                        tokenStr += chr;
                    } else {
                        tokens.emplace_back(Token(tokenStr, NUMBER));
                        tokenStr = "";
                        state = TS_DEFAULT;
                        index -= 1; // push back the character.
                    }
                    break;
            }
        } // for
        return tokens;
    }
}

