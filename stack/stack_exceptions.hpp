#ifndef CUCUMBERLIST_STACK_EXCEPTIONS_HPP
#define CUCUMBERLIST_STACK_EXCEPTIONS_HPP

#include <exception>
//========================================================================
// Классы StackOverflow и StackUnderflow представляют две основные
// исключительные ситуации, которые могут возникнуть при работе со стеком
//========================================================================
class StackOverflow : public std::exception
{
public:
    StackOverflow() : reason("Stack Overflow") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
private:
    const char* reason; // ! const
};


class StackUnderflow : public std::exception
{
public:
    StackUnderflow() : reason("Stack Underflow") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
private:
    const char* reason; // ! const
};

#endif //CUCUMBERLIST_STACK_EXCEPTIONS_HPP
