//
// Created by irwin on 05/05/2021.
//

#include "../header/repl.h"
#include <string>
#include <iostream>
#include "../header/tokenizer.h"
#include "../header/parser.h"
#include "../header/evaluator.h"
#include "../header/object.h"

namespace pic {
    void Repl::Start() {
        const std::string PROMTP = "Wellcome to PicLang\nPlease type some commands and press ENTER...\n";
        std::cout << PROMTP;
        std::string input;
        while (true) {
            std::cout << ">> ";
            std::getline(std::cin, input);
            if (!input.empty()) {
                input += " "; // ending character
                Parser parser;
                parser.tokens = pic::Tokenizer::Tokenize(input);
                Node* node = parser.Parse();
                if (node != nullptr) {
                    Evaluator evaluator;
                    Obj* evaluated = evaluator.Evaluate(node);
                    if (evaluated != nullptr) {
                        std::cout << evaluated->Inspect() << std::endl;
                    }
                    delete evaluated;
                }
                delete node;
            } else {
                break;
            }
        }
    }
}

