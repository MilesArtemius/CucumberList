#include "compile_stack_checker.hpp"

char* toPostfix(char* infix) {
    StackArray<Operator>* stack = new StackArray<Operator>(EXPRESSION_LENGTH);

    stack->push(Operator('('));
    for (int i = 0; infix[i] != 0; ++i) {
        if (Operator::isOperable(infix[i])) stack->push(Operator(infix[i]));
    }
    return nullptr;
}
