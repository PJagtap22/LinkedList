// main.cpp
#include <iostream>
#include "Dll.h"

using namespace std;

int main()
{
    List list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);

    List list2(list1);

    cout << "Original list1: ";
    list1.display();
    cout << "Copied list2: ";
    list2.display();

    list2.add(4);

    cout << "Modified list2: ";
    list2.display();

    List list3;
    list3 = list1;

    cout << "Assigned list3: ";
    list3.display();

    return 0;
}
