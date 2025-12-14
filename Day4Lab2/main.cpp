#include <iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
    AVLTree * tree = new AVLTree();

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

/// problem : Inserting/deleting a tree is possible and only works on one side.
/// How can we keep the tree "close to balanced" at all times?
/// ==========================================================
/// First logical step:
/// After each Insert or Delete, we check if the tree is tilted. If it is, we correct it.
///   => We need to measure the balance.
///   => We need to fix the balance.
/// ==========================================================
/// how do we measure balance? ( balance = height(left) - height(right) )
/// Each node has: A left subtree & A right subtree
/// If the difference between them is large → imbalance
///    => balance = 0  : perfect
///    => balance = ±1 : acceptable
///    => balance = ±2 : imbalance
/// ===========================================================
/// how do we fix?
/// If the tree is tilted: Change its shape Without breaking the BST property
/// by Reorder the links (Rotation)
/// ===========================================================
/// Logical Deduction:
/// So we need to: Store the height of each node & Calculate the balance factor
/// If there's an imbalance, we perform rotations
/// We do this after: Insert & Delete
/// ===========================================================
/// Imbalance cases: ( AVL ) node : Adelson - Velsky and Landis | height(left) − height(right) | ≤ 1
///    => Left Left (LL)
///    => Right Right (RR)
///    => Left Right (LR)
///    => Right Left (RL)

