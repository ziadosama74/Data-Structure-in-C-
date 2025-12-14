#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H
#include "LinkedList.h"
class QueueLinkedList
{
    private:
        int Front;
        int Rear;
        LinkedList * LS;
        bool IsEmpty()
        {
            return Front == -1 && Rear == -1;
        }
    public:
        QueueLinkedList()
        {
            Front = Rear = -1;
            LS = new LinkedList();
        }
        void Enqueue(int _data)
        {
            if(IsEmpty()) Front = 0;
            LS->add(_data);
            Rear++;
        }
        int Dequeue()
        {
            int De_Val = -1;
            if(!IsEmpty())
            {
                LS->DeleteFromFirst(&De_Val);
                Rear--;
                if(Rear == -1)Front = -1;
            }
            else
            {
                cout << "Queue is empty .. !!" << endl;
            }
            return De_Val;
        }
        void DisplayQueue()
        {
            LS->Display();
        }
};

#endif // QUEUELINKEDLIST_H
