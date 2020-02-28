#include <iostream>
#include"list.hpp"
using namespace std;

//TODO: rename to "main" to launch!
int main_list()
{
    List<int> L1;

    L1 += 8;
    L1 += 1;
    //L1 += 5;
    L1 += 0;
    cout << "1 List is " << L1 << endl << endl;
    List<int> L2;
    L2 += 8;
    L2 += 1;
    L2 += 0;

    List<int> L42;
    L42 += 8;
    L42 += 1;

    cout << "1 List is " << L1 << endl;
    cout << "2 List is " << L2 << endl;
    cout << "First List = Second List? ";
    if (L1 == L2)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    cout << "1 List is " << L1 << endl;
    cout << "42 List is " << L42 << endl;
    cout << "First List = Forty second List? ";
    if (L1 == L42)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    cout << endl;


    List<int> L3 = L1 & L42;
    cout << "3 List (first & forty second) is " << L3 << endl;

    List<int> L4 = L1 | L42;
    cout << "4 List (first | forty second) is " << L4 << endl;

    L1 = L3;
    cout << "L3 (" << L3 << ") copied to L1 (" << L1 <<")" << endl;

    List<int> L5 = L3.merge(L4);
    cout << "L3 (" << L3 << ") merged with L4 (" << L4 <<") <- " << L5 << endl;

    return 0;
}