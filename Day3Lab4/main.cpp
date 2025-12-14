/// 4- Edit the Linked List in Day 1 to be a sorted Linked List
/// ===========================================================
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList * LS = new LinkedList();
    LS->add(10);
    LS->add(5);
    LS->add(1);
    LS->Display();
    return 0;
}
