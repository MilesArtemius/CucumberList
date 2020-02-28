#include <iostream>
#include "stack_checker.hpp"

using namespace std;

//TODO: rename to "main" to launch!
int main()
{
    const char* text00 = " ok ";
    cout << text00 << ": " << (testBalanceBrackets(text00) ? "right" : "wrong") << endl;
    const char* text01 = "( ) ok ";
    cout << text01 << ": " << (testBalanceBrackets(text01) ? "right" : "wrong") << endl;
    const char* text02 = "( ( [] ) ) ok ";
    cout << text02 << ": " << (testBalanceBrackets(text02) ? "right" : "wrong") << endl;
    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    cout << text03 << ": " << (testBalanceBrackets(text03) ? "right" : "wrong") << endl;
    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    cout << text04 << ": " << (testBalanceBrackets(text04) ? "right" : "wrong") << endl;
    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    cout << text05 << ": " << (testBalanceBrackets(text05) ? "right" : "wrong") << endl;
    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    cout << text06 << ": " << (testBalanceBrackets(text06) ? "right" : "wrong") << endl;
    return 0;
}
