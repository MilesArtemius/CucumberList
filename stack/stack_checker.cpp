#include "stack_checker.hpp"

bool testBalanceBrackets(const char* text, int maxDeep)
{
    Stack<char>* stack;
    if (maxDeep == NULL_DEPTH)
    {
        stack = new StackList<char>();
    }
    else
    {
        stack = new StackArray<char>(maxDeep);
    }
    bool isBalanceBrackets = true; // изменим на false при обнаружении ошибки
// если в структуре скобок есть ошибки,
// может возникнуть прерывание при работе со стеком
    try {
        char cText = '\0'; // очередной символ текста
// Цикл анализа текста: учитываются только скобки, остальные символы - пропускаются.
// Цикл завершается при достижении конца текста или обнаружении первого несоответствия скобок.
        for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true);
             i++) {
            switch (cText) {
                case '(': case '[': case '{':
                    stack->push(cText); // любая левая скобка помещается в стек
                    break;
                case ')': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '(') {
                        isBalanceBrackets = false;
                    }
                    break;
                case ']':
                    if (stack->pop() != '[') {
                        isBalanceBrackets = false;
                    }
                    break;
                case '}':
                    if (stack->pop() != '{') {
                        isBalanceBrackets = false;
                    }
                    break;
            }
        }
// Достигнут конец текста. Все в порядке, если стек пуст и есть баланс скобок
                isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
    }
    catch (StackUnderflow) {
        isBalanceBrackets = false; // Обнаружена лишняя правая скобка
    }
    catch (StackOverflow) {
        isBalanceBrackets = false; // Вложенность скобок больше допустимой maxDeep
    }
    delete stack;
    return isBalanceBrackets;
}
