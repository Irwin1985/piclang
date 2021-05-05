//
// Created by irwin on 05/05/2021.
//

#ifndef PICLANG_OBJECT_H
#define PICLANG_OBJECT_H
#include <iostream>

namespace pic {
    enum objType {
        OBJ_NUMBER,
        OBJ_BOOLEAN,
    };

    // Object base class
    class Obj {
    public:
        ~Obj() {};
        virtual objType Type() = 0;
        virtual std::string Inspect() = 0;
    };

    // Number object class
    class NumberObj : public Obj {
    public:
        double value = 0.00;
        NumberObj() = default;
        NumberObj(double value) { this->value = value; };
        objType Type() { return OBJ_NUMBER; };
        std::string Inspect() { return std::to_string(value); };
    };

    // Boolean object class
    class BooleanObj : public Obj {
    public:
        bool value = false;
        BooleanObj() = default;
        BooleanObj(bool value) { this->value = value; }
        objType Type() { return OBJ_BOOLEAN; };
        std::string Inspect() { return value ? "true" : "false"; }
    };
}

#endif //PICLANG_OBJECT_H
