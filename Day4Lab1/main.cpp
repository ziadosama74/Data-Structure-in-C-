#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST * tree = new BST();

    tree->Insert(Employee(10, "Ziad", 25));
    tree->Insert(Employee(5, "Osama", 40));
    tree->Insert(Employee(20, "Mahmoud", 28));
    tree->Insert(Employee(15, "Ali", 32));
    tree->Insert(Employee(30, "Omar", 40));

    cout << "DFS (InOrder):\n";
    tree->DFS();
    cout << "=============================\n";
    tree->Delete(20);
    tree->DFS();

    cout << "\nMinimum ID: " << tree->GetMinimum().ID << endl;
    cout << "Maximum ID: " << tree->GetMaximum().ID << endl;

    return 0;
}

