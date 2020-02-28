#ifndef CUCUMBERLIST_STACK_LIST_HPP
#define CUCUMBERLIST_STACK_LIST_HPP

#include "stack.hpp"
#include "../list/list.hpp"
#include "stack_exceptions.hpp"

template <class T>
class StackList : public Stack<T>, public List<T>
{
public:
    explicit StackList(); // size задает размер стека "по умолчанию"
    StackList(const StackList<T>& src);
    virtual ~StackList() = default;

    void push(const T& e) override ;
    const T& pop() override ;
    bool isEmpty() override { return List<T>::Size == 0; }
};



template<class T>
StackList<T>::StackList() : List<T>() {}

template<class T>
StackList<T>::StackList(const StackList<T> &src) : List<T>(src) {}



template<class T>
void StackList<T>::push(const T &e) {
    List<T>::add_unsorted(e);
}



//WARNING! Won't work for T without copy constructor!!!
template<class T>
const T &StackList<T>::pop() {
    if (List<T>::Size == 0)
        throw StackUnderflow();
    T* last = new T(List<T>::get(List<T>::Size - 1));
    List<T>::remove(List<T>::Size - 1);
    return *last;
}

#endif //CUCUMBERLIST_STACK_LIST_HPP
