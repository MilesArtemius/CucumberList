#include <iostream>
#include "compile_stack_checker.hpp"

using namespace std;

//TODO: rename to "main" to launch!
//TODO: какие тесты тут нужны я, если честно, не знаю...
int main() {
    const char* string = "1+2*3/5+2^3";
    const char* str = toPostfix(string);
    int ans = calculate(str);
    cout << string << " = " << str <<  " = " << ans << endl;
}