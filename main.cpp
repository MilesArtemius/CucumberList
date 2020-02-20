#include <iostream>
#include"list.h"
using namespace std;

int main()
{
    List L1;

    L1 += 8;
    L1 += 1;
    L1 += 5;
    L1 += 0;
    cout << "1 List is " << L1 << endl;
    List L2;
    L2 += 8;
    L2 += 1;
    L2 += 0;

    cout << "1 List is " << L1 << endl;
    cout << "2 List is " << L2 << endl;
    cout << "First List = Second List? ";
    if ((L1 == L2) == 1)
    {
        cout << "Yes";
    }
    else cout << "No" << endl;


    List L3 = L1 & L2;
    cout << "3 List (first & second) is " << L3 << endl;

    List L4 = L1 | L2;
    cout << "4 List (first | second) is " << L4 << endl;

    L4 = L3;
    cout << "L3 (" << L3 << ") copied to L4 (" << L4 <<")" << endl;

    return 0;
}