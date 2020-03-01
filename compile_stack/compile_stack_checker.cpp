#include "compile_stack_checker.hpp"

char* toPostfix(const char* infix) {
    int size = getLength(infix) + 1;
    int index = 0;

    StackArray<Operator>* stack = new StackArray<Operator>(size);
    char* output = (char*) calloc(size, sizeof(char));

    stack->push(Operator('('));
    for (int i = 0; infix[i] != 0; ++i) {
        if (Operator::isOperable(infix[i])) {
            Operator op(infix[i]);
            if (op.isOpeningParenthesis()) {
                stack->push(op);

            } else if (op.isClosingParenthesis()) {
                Operator curr = stack->pop();
                while (!curr.isOpeningParenthesis()) {
                    output[index++] = curr.deoperate();
                    curr = stack->pop();
                }

            } else {
                Operator curr = stack->pop();
                while (curr.prioritize() >= op.prioritize()) {
                    output[index++] = curr.deoperate();
                    curr = stack->pop();
                }
                stack->push(curr);
                stack->push(op);
            }

        } else {
            output[index++] = infix[i];
        }
    }

    Operator curr = stack->pop();
    while (!curr.isOpeningParenthesis()) {
        output[index++] = curr.deoperate();
        curr = stack->pop();
    }

    return output;
}

int calculate(const char* postfix) {
    int size = getLength(postfix);
    StackArray<char>* expression = new StackArray<char>(size);
    StackArray<int>* args = new StackArray<int>(size);

    for (int i = size - 1; i >= 0; --i) expression->push(postfix[i]);

    while (!expression->isEmpty()) {
        char iter = expression->pop();

        if (Operator::isOperable(iter)) {
            Operator action(iter);
            args->push(action.apply(args->pop(), args->pop()));
        } else {
            args->push(iter - NUMBER_OFFSET);
        }
    }

    return args->pop();
}



int getLength(const char* any) {
    int size;
    for (size = 0; any[size] != 0; ++size);
    return size;
}
