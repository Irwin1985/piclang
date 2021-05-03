//
// Created by irwin on 03/05/2021.
//
#include <string>
#include "../header/tokenizer.h"

namespace pic {

    bool Tokenizer::IsOp(char chr) {
        return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '(' || chr == ')';
    }

    TokenType Tokenizer::FindOpType(char chr) {
        TokenType type = UNKNOWN;
        switch (chr) {
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
            case '(':
                type = LEFT_PAREN;
                break;
            case ')':
                type = RIGHT_PAREN;
                break;
        }
        return type;
    }

    std::list<Token> Tokenizer::Tokenize(std::string source) {
        std::list<Token> tokens;
        std::string token;
        token = "";
        TokenState state = TS_DEFAULT;

        for (int index = 0; index < source.size(); index++) {
            char chr = source[index];

            if (state == TS_DEFAULT) {
                TokenType opType = FindOpType(chr);
                if (IsOp(chr)) {
                    tokens.emplace_back(Token(chr, opType));
                }
                else if (isdigit(chr)) {
                    token += chr;
                    state = TS_NUMBER;
                }
            }
            else if (state == TS_NUMBER) {
                if (isdigit(chr)) {
                    token += chr;
                } else {
                  tokens.emplace_back(token, NUMBER);
                  token = "";
                  state = TS_DEFAULT;
                  index -= 1; // push back the character.
                }
            }
        } // for
        return tokens;
    }
}

