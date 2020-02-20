#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node* pNext = nullptr;
    Node* pPrev = nullptr;
};

class List
{
public:

    Node* head;
    Node* tail;
    int Size = 0;

    List();
    ~List();

    List(const List& l1); // конструктор копирования
    List& operator=(const List& l1);
    List(List&& other);//конструктор пермещения

    List& operator+= (const int& newData);//оператор ввода
    void add(int x);

    friend ostream& operator<< (ostream& out, const List& l);//оператор вывода
    bool operator==(const List& obj);//оператор сравнения списков
    List& operator&(List& l1);//оператор формирования третьего списка, состоящего из элементов, присутствующих в первом И втором

    List& operator|(List& l1); //оператор формирования третьего списка, состоящего из элементов, присутствующих в первом ИЛИ во втором
    List& merge(List& l1);

private:
    bool contains(int i);
    void clear();
};
