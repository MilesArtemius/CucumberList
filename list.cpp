#include "list.hpp"


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
    *this = l1;
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

List::List(List&& other) noexcept : //конструктор перемещения
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
    Node* temp = new Node();
    temp->data = x;

    if (head)
    {
        Node* current = head;
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
        out << tmpNode->data;
        if (tmpNode->pNext) out << " ";
        tmpNode = tmpNode->pNext;
    }
    return out;
}

bool List::operator==(const List& obj)// оператор сравнения списков
{
    if (Size == 0 && obj.Size == 0) return true;
    if (Size != obj.Size) return false;

    Node* currentElement = head;
    Node* toCompare = obj.head;
    bool equal = true;
    while ((currentElement != nullptr) && (toCompare != nullptr))
    {
        equal &= currentElement->data == toCompare->data;
        currentElement = currentElement->pNext;
        toCompare = toCompare->pNext;
    }
    return equal && ((!currentElement) && (!toCompare));
}

List& List::operator&(List& l1)
{
    List* newList = new List();

    Node* ptr1 = this->head;
    while (ptr1)
    {
        if (l1.contains(ptr1->data)) *newList += ptr1->data;
        ptr1 = ptr1->pNext;
    }

    return *newList;
}



List& List::operator|(List& l1)
{
    return this->merge(l1, true);
}

List& List::merge(List& l1, bool isXOR)
{
    List* newList = new List();

    Node* ptr1 = this->head;
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



bool List::contains(int i) {
    Node* current = head;
    while ((current) && (current->data <= i)) {
        if (current->data == i) return true;
        current = current->pNext;
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
