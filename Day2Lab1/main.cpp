#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "StackLinkedList.h"
using namespace std;

int main()
{
    StackLinkedList* SLS1 = new StackLinkedList();
    SLS1->push(1);
    SLS1->push(2);
    SLS1->push(3);
    SLS1->push(4);
    SLS1->push(5);
    SLS1->DispayStack();
    cout << "SLS1 Element pop is : " << SLS1->pop() << endl;
    SLS1->DispayStack();
    SLS1->push(6);
    SLS1->DispayStack();
}
