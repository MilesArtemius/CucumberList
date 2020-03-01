#ifndef CUCUMBERLIST_OPERATOR_HPP
#define CUCUMBERLIST_OPERATOR_HPP

class Operator {
private:
    enum priority {PARENTHESIS, ADDITION, MULTIPLICATION, POWER};
    enum type : char {O_PAR = '(', C_PAR = ')', PLUS = '+', MINUS = '-', MULT = '*', DEL = '/', POW = '^'};

    type signum;
    priority prior;

public:
    explicit Operator(char character);
    Operator() = default;
    char deoperate();
    int prioritize();

    static bool isOperable(char symbol);
    bool isOpeningParenthesis();
    bool isClosingParenthesis();

    int apply(int firstOperand, int secondOperand);
};

#endif //CUCUMBERLIST_OPERATOR_HPP
