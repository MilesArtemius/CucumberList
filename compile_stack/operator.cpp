#include <cmath>
#include "operator.hpp"

Operator::Operator(char character) {
    signum = static_cast<type>(character);
    switch (signum) {
        case O_PAR:
        case C_PAR:
            prior = PARENTHESIS;
            break;
        case PLUS:
        case MINUS:
            prior = ADDITION;
            break;
        case MULT:
        case DEL:
            prior = MULTIPLICATION;
            break;
        case POW:
            prior = POWER;
            break;
    }
}

char Operator::deoperate() {
    return signum;
}

int Operator::prioritize() {
    return prior;
}



bool Operator::isOperable(char symbol) {
    type possibility = static_cast<type>(symbol);
    switch (possibility) {
        case O_PAR:
        case C_PAR:
        case PLUS:
        case MINUS:
        case MULT:
        case DEL:
        case POW:
            return true;
        default:
            return false;
    }
}



int Operator::apply(int firstOperand, int secondOperand) {
    switch (signum) {
        case PLUS:
            return firstOperand + secondOperand;
        case MINUS:
            return firstOperand - secondOperand;
        case MULT:
            return firstOperand * secondOperand;
        case DEL:
            return firstOperand / secondOperand;
        case POW:
            return (int) pow(firstOperand, secondOperand);
        default:
            return 0;
    }
}
