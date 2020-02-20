#include <iostream>
#include"list.h"
#include "list.h"


using namespace std;

List::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    clear();
}



List::List(const List &l1) : List() {
    this->operator=(l1);
}

List& List::operator=(const List& l1)
{
    if (this != &l1)
    {

        this->clear();
        Node *temp = l1.head;

        while (temp != nullptr)
        {
            add(temp->data);
            temp = temp->pNext;
        }
    }
    return *this;
}

List::List(List&& other) : //конструктор перемещения
        head(other.head),
        tail(other.tail)
{
    Size = other.Size;
    other.head = nullptr;
    other.tail = nullptr;
}



List& List::operator+=(const int& newData)//оператор ввода
{
    this->add(newData);
    return *this;
}

void List::add(int x)
{
    Node* temp = new Node;
    temp->pNext = nullptr;
    temp->data = x;

    if (head)
    {
        Node* current = head;
        bool isFinal = false;
        while (current->data < x)
        {
            if (!current->pNext)
            {
                isFinal = true;
                break;
            }
            current = current->pNext;
        }

        if (isFinal)
        {
            temp->pPrev = tail;
            tail->pNext = temp;
            tail = temp;
        }
        else
        {
            if (current->pPrev)
            {
                Node* prev = current->pPrev;
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



ostream& operator<< (ostream& out, const List& i)//оператор вывода
{
    Node* tmpNode = i.head;
    while (tmpNode)
    {
        out << tmpNode->data << " ";
        tmpNode = tmpNode->pNext;
    }
    return out;
}

bool List::operator==(const List& obj)// оператор сравнения списков
{
    if (Size == 0 && obj.Size == 0)
        return true;
    if (Size != obj.Size)
        return false;
    if (head->data == obj.head->data)
    {
        Node* currentElement = head;
        Node* toCompare = obj.head;
        while (currentElement != nullptr)
        {
            if (currentElement->data != toCompare->data)
                return false;
            currentElement = currentElement->pNext;
            toCompare = toCompare->pNext;
        }
        return false;
    }
    return false;
}

List& List::operator&(List& l1)
{
    List* lst3 = new List();
    Node* ptr1 = this->head;
    Node* ptr2;

    while (ptr1)
    {
        ptr2 = l1.head;
        while (ptr2)
        {
            if (ptr1->data == ptr2->data)
            {
                lst3->add(ptr1->data);
            }
            ptr2 = ptr2->pNext;
        }
        ptr1 = ptr1->pNext;
    }
    return *lst3;
}



List& List::operator|(List& l1)
{
    List* list3 = new List();
    Node* current = head;
    while (current)
    {
        *list3 += current->data;
        current = current->pNext;
    }
    current = l1.head;
    while (current)
    {
        *list3 += current->data;
        current = current->pNext;
    }
    return *list3;

}

List& List::merge(List& l1)
{
    Node* current = head;
    while (current->pNext)
    {
        current = current->pNext;
    }
    Node* current1 = l1.head;
    while (current)
    {
        current->pNext = new Node;
        current->pNext->data = current1->data;
        current = current->pNext;
        Node* temp;
        temp = current1->pNext;
        delete current1;
        current1 = temp;
    }
    l1.head = nullptr;
    return *this;
}



bool List::contains(int i) {
    Node* current = head;
    while (current->data <= i) {
        if (current->data == i) {}
    }
    return false;
}

void List::clear() {
    Node* current = head;
    Node* next = nullptr;
    while (current)
    {
        next = current->pNext;
        free(current);
        current = next;
    }
    this->head = this->tail = nullptr;
    this->Size = 0;
}
