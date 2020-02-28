#ifndef CUCUMBERLIST_LIST_HPP
#define CUCUMBERLIST_LIST_HPP

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data = 0;
    Node* pNext = nullptr;
    Node* pPrev = nullptr;
};

template <class T>
class List
{
public:

    Node<T>* head;
    Node<T>* tail;
    int Size = 0;

    List();
    ~List();

    List(const List& l1); // конструктор копирования
    List& operator=(const List& l1);
    List(List&& other) noexcept;//конструктор пермещения

    List& operator+= (const T& newData);//оператор ввода
    void add(T x);
    void add_unsorted(T x);
    void remove(int pos);
    T& get(int pos);

    template <class K>
    friend ostream& operator<< (ostream& out, const List<K>& l);//оператор вывода
    bool operator==(const List& obj);//оператор сравнения списков
    List& operator&(List& l1);//оператор формирования третьего списка, состоящего из элементов, присутствующих в первом И втором

    List& operator|(List& l1); //оператор формирования третьего списка, состоящего из элементов, присутствующих в первом ИЛИ во втором
    List& merge(List& l1, bool isXOR = false);

private:
    bool contains(T i);
    void clear();
};



template <class T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
List<T>::~List()
{
    clear();
}



template <class T>
List<T>::List(const List<T> &l1) : List<T>() {
    *this = l1;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l1)
{

    if (this != &l1)
    {

        this->clear();
        Node<T> *temp = l1.head;

        while (temp != nullptr)
        {
            add(temp->data);
            temp = temp->pNext;
        }
    }
    return *this;
}

template <class T>
List<T>::List(List<T>&& other) noexcept : //конструктор перемещения
        head(other.head),
        tail(other.tail)
{
    Size = other.Size;
    other.head = nullptr;
    other.tail = nullptr;
}



template <class T>
List<T>& List<T>::operator+=(const T& newData)//оператор ввода
{
    this->add(newData);
    return *this;
}

template <class T>
void List<T>::add(T x)
{
    Node<T>* temp = new Node<T>();
    temp->data = x;

    if (head)
    {
        Node<T>* current = head;
        while ((current->data < x) && (current->pNext)) current = current->pNext;

        if ((current == tail) && (current->data < x))
        {
            temp->pPrev = tail;
            tail->pNext = temp;
            tail = temp;
        }
        else
        {
            if (current->pPrev)
            {
                Node<T>* prev = current->pPrev;
                prev->pNext = temp;
                temp->pPrev = prev;
                current->pPrev = temp;
                temp->pNext = current;
            }
            else
            {
                current->pPrev = temp;
                temp->pNext = current;
                head = temp;
            }
        }
    }
    else
    {
        temp->pPrev = nullptr;
        head = tail = temp;
    }
    Size++;
}

template <class T>
void List<T>::add_unsorted(T x)
{
    Node<T>* temp = new Node<T>();
    temp->data = x;

    if (head)
    {
        temp->pPrev = tail;
        tail->pNext = temp;
        tail = temp;
    }
    else
    {
        temp->pPrev = nullptr;
        head = tail = temp;
    }
    Size++;
}

template<class T>
void List<T>::remove(int pos) {
    if (pos >= Size) return;

    Node<T>* current = head;
    int position = pos;

    while (position > 0)
    {
        current = current->pNext;
        position--;
    }

    if ((current == head) && (current == tail))
    {
        head = tail = nullptr;
    }
    else if (current == head)
    {
        head = current->pNext;
        head->pPrev = nullptr;
    }
    else if (current == tail)
    {
        tail = current->pPrev;
        tail->pNext = nullptr;
    }
    else if ((current != head) && (current != tail))
    {
        current->pPrev->pNext = current->pNext;
        current->pNext->pPrev = current->pPrev;
    }

    Size--;
    free(current);
}

template<class T>
T &List<T>::get(int pos) {
    if (pos >= Size) throw runtime_error("List underflow!");

    Node<T>* current = head;
    int position = pos;

    while (position > 0)
    {
        current = current->pNext;
        position--;
    }

    return current->data;
}



template <class K>
ostream& operator<< (ostream& out, const List<K>& i)//оператор вывода
{
    Node<K>* tmpNode = i.head;
    while (tmpNode)
    {
        out << tmpNode->data;
        if (tmpNode->pNext) out << " ";
        tmpNode = tmpNode->pNext;
    }
    return out;
}

template <class T>
bool List<T>::operator==(const List<T>& obj)// оператор сравнения списков
{
    if (Size == 0 && obj.Size == 0) return true;
    if (Size != obj.Size) return false;

    Node<T>* currentElement = head;
    Node<T>* toCompare = obj.head;
    bool equal = true;
    while ((currentElement != nullptr) && (toCompare != nullptr))
    {
        equal &= currentElement->data == toCompare->data;
        currentElement = currentElement->pNext;
        toCompare = toCompare->pNext;
    }
    return equal && ((!currentElement) && (!toCompare));
}

template <class T>
List<T>& List<T>::operator&(List<T>& l1)
{
    List<T>* newList = new List<T>();

    Node<T>* ptr1 = this->head;
    while (ptr1)
    {
        if (l1.contains(ptr1->data)) *newList += ptr1->data;
        ptr1 = ptr1->pNext;
    }

    return *newList;
}



template <class T>
List<T>& List<T>::operator|(List<T>& l1)
{
    return this->merge(l1, true);
}

template <class T>
List<T>& List<T>::merge(List<T>& l1, bool isXOR)
{
    List<T>* newList = new List<T>();

    Node<T>* ptr1 = this->head;
    while (ptr1)
    {
        *newList += ptr1->data;
        ptr1 = ptr1->pNext;
    }

    ptr1 = l1.head;
    while (ptr1)
    {
        if ((!isXOR) || (!newList->contains(ptr1->data))) *newList += ptr1->data;
        ptr1 = ptr1->pNext;
    }

    return *newList;
}



template <class T>
bool List<T>::contains(T i) {
    Node<T>* current = head;
    while ((current) && (current->data <= i)) {
        if (current->data == i) return true;
        current = current->pNext;
    }
    return false;
}

template <class T>
void List<T>::clear() {
    Node<T>* current = head;
    Node<T>* next = nullptr;
    while (current)
    {
        next = current->pNext;
        free(current);
        current = next;
    }
    this->head = this->tail = nullptr;
    this->Size = 0;
}

#endif //CUCUMBERLIST_LIST_HPP
