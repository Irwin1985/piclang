#include "header/tokenizer.h"

#include <iostream>
#include "header/prettyprint.h"

int main() {
    std::string expression = "219+341+19";
    expression += " ";

    pic::Tokenizer tokenizer;
    std::list<pic::Token> tokens = tokenizer.Tokenize(expression);
    std::cout << "---------------------\n";
    pic::PrettyPrint(tokens);


//    for (pic::Token token : tokens) {
//        std::cout << token.toString() << "\n";
//    }

    return 0;
}
