#ifndef CUCUMBERLIST_WRONG_STACK_SIZE_HPP
#define CUCUMBERLIST_WRONG_STACK_SIZE_HPP

#include <exception>

//==============================================================
// Исключительная ситуация WrongStackSize может возникнyть,
// если в конструкторе стека неправильно задан размер.
//==============================================================
class WrongStackSize : public std::exception
{
public:
    WrongStackSize() : reason("Wrong Stack Size") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
private:
    const char* reason; // ! const
};


#endif //CUCUMBERLIST_WRONG_STACK_SIZE_HPP
