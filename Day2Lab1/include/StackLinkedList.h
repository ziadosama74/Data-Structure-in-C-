#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include "Node.h"
#include "LinkedList.h"

class StackLinkedList
{
    private:
        LinkedList * LS;
        int Top;
    public:
        StackLinkedList()
        {
            LS = new LinkedList();
            Top = - 1;
        }
        void push(int _data)
        {
            LS->add(_data);
            Top++;
        }
        int pop()
        {
            int PopVal = 0 ;
            LS->DeleteByIndex(Top,&PopVal);
            Top--;
            return PopVal;
        }
        void DispayStack()
        {
            LS->Display();
        }
};

#endif // STACKLINKEDLIST_H
