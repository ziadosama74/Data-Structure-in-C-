#include <iostream>
#include "QueueLinkedList.h"
using namespace std;
int main()
{
    QueueLinkedList * QLS = new QueueLinkedList();
    QLS->Enqueue(1);
    QLS->Enqueue(2);
    QLS->Enqueue(3);
    QLS->Enqueue(4);
    QLS->Enqueue(5);
    QLS->Enqueue(6);
    QLS->Enqueue(7);
    QLS->DisplayQueue();
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    QLS->DisplayQueue();
    cout << "Enqueue 8 " << endl;
    QLS->Enqueue(8);
    QLS->DisplayQueue();
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    cout << "Dequeue Element is : " << QLS->Dequeue() << endl;
    return 0;
}
