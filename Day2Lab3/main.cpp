#include <iostream>
#include "CircularQueue.h"
using namespace std;

int main()
{
    CircularQueue * CQ = new CircularQueue(5);
    bool Ret = false;
    Ret = CQ->Enqueue(1);
    cout << ((Ret) ? "true" : "false") << endl;
    Ret = CQ->Enqueue(2);
    cout << ((Ret) ? "true" : "false") << endl;
    Ret = CQ->Enqueue(3);
    cout << ((Ret) ? "true" : "false") << endl;
    Ret = CQ->Enqueue(4);
    cout << ((Ret) ? "true" : "false") << endl;
    Ret = CQ->Enqueue(5);
    cout << ((Ret) ? "true" : "false") << endl;
    CQ->Display();
    Ret = CQ->Dequeue();
    cout << ((Ret) ? "true" : "false") << endl;
    cout << "======================" << endl;
    CQ->Display();
    Ret = CQ->Enqueue(6);
    cout << ((Ret) ? "true" : "false") << endl;
    cout << "======================" << endl;
    CQ->Display();
    Ret = CQ->Enqueue(6);
    cout << ((Ret) ? "true" : "false") << endl;
    CQ->Display();
    return 0;
}
