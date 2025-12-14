#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
///  reverse list in return list
/// ============================
LinkedList* Reverse( LinkedList * LL)
{
    LinkedList* NewList = new LinkedList();
    Node* current = LL->Gettail();
    while (current != nullptr)
    {
        NewList->insertEnd(current->data);
        current = current->prev;
    }
    return NewList;
}

int main()
{
//    LinkedList * List = new LinkedList();
//
//    List->insertEnd(1);
//    List->insertEnd(2);
//    List->insertEnd(3);
//    List->insertEnd(4);
//    List->insertEnd(5);
//    List->insertEnd(6);
//    List->insertEnd(7);
//    List->insertEnd(8);
//    List->insertEnd(9);
//    List->insertEnd(10);
//    List->Display();
//    List->Remove_Every_K_th(3);
//    cout << endl;
//    List->Display();
    cout << "\n====================================" << endl;
    LinkedList * List1 = new LinkedList();
    LinkedList * List2 = new LinkedList();
    List1->insertEnd(1);
    List1->insertEnd(2);
    List1->insertEnd(3);
    List1->insertEnd(4);
    List1->insertEnd(6);
    cout << "List 1 : \n========" << endl;
    List1->Display();
    List2->insertEnd(2);
    List2->insertEnd(4);
    List2->insertEnd(6);
    List2->insertEnd(8);
    cout << "\nList 2 : \n========" << endl;
    List2->Display();
    cout <<"\ncommon elements \n================ " << endl;
    LinkedList * intersectionList =  new LinkedList();
    intersectionList = List1->Intersection(List2);
    intersectionList->Display();

//    cout << endl;
//    List->insertAfter(4,2);
//    List->Display();
//    cout << endl;
//    List->insertBefore(5,4);
//    List->Display();
//    cout << endl;
//    cout << "\nThe number od nodes inside the Linked List is : ";
//    cout << List->Get_Nodes_Number() << endl;
//    List->Reverse();
//    List->Display();
//    LinkedList * List_Rev = new LinkedList();
//    List_Rev = Reverse(List);
//    cout << endl;
//    List_Rev->Display();
//    int Ret_By_Index = List_Rev->getDataByIndex(4);
//    cout <<"\nRet_By_Index = " << Ret_By_Index << endl;
//    List_Rev->insertEnd(6);
//    cout << endl;
//    List_Rev->Display();
//    if(List->Search(35))
//        cout<<"found";
//    else cout<<"Not found";
//
//
//    bool deleted = List->Delete(10);
    return 0;

}
