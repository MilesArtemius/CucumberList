#ifndef CUCUMBERLIST_COMPILE_STACK_CHECKER_HPP
#define CUCUMBERLIST_COMPILE_STACK_CHECKER_HPP

#define NUMBER_OFFSET 48

#include "../stack/stack_array.hpp"
#include "operator.hpp"
#include <cstdlib>

char* toPostfix(const char* infix);

int calculate(const char* postfix);



int getLength(const char* any);


#endif //CUCUMBERLIST_COMPILE_STACK_CHECKER_HPP
