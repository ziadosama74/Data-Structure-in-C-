#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>
#include "AVLNode.h"

using namespace std;

class AVLTree
{
private:
    AVLNode* root;

    /// ===== Helpers =====
    int Height(AVLNode* n)
    {
        return n ? n->height : 0;
    }

    int Balance(AVLNode* n)
    {
        return n ? Height(n->left) - Height(n->right) : 0;
    }

    AVLNode* RightRotate(AVLNode* y)
    {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(Height(y->left), Height(y->right)) + 1;
        x->height = max(Height(x->left), Height(x->right)) + 1;

        return x;
    }

    AVLNode* LeftRotate(AVLNode* x)
    {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(Height(x->left), Height(x->right)) + 1;
        y->height = max(Height(y->left), Height(y->right)) + 1;

        return y;
    }

    /// ===== Insert =====
    AVLNode* Insert(AVLNode* node, Employee emp)
    {
        if (!node)
            return new AVLNode(emp);

        if (emp.ID < node->data.ID)
            node->left = Insert(node->left, emp);
        else if (emp.ID > node->data.ID)
            node->right = Insert(node->right, emp);
        else
            return node;

        node->height = 1 + max(Height(node->left), Height(node->right));
        int balance = Balance(node);

        /// LL
        if (balance > 1 && emp.ID < node->left->data.ID)
            return RightRotate(node);

        /// RR
        if (balance < -1 && emp.ID > node->right->data.ID)
            return LeftRotate(node);

        /// LR
        if (balance > 1 && emp.ID > node->left->data.ID)
        {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        /// RL
        if (balance < -1 && emp.ID < node->right->data.ID)
        {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

    /// ===== Min Node =====
    AVLNode* MinNode(AVLNode* node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    /// ===== Delete =====
    AVLNode* Delete(AVLNode* root, int id)
    {
        if (!root)
            return root;

        if (id < root->data.ID)
            root->left = Delete(root->left, id);
        else if (id > root->data.ID)
            root->right = Delete(root->right, id);
        else
        {
            /// One or zero child
            if (!root->left || !root->right)
            {
                AVLNode* temp = root->left ? root->left : root->right;

                if (!temp)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else
            {
                AVLNode* temp = MinNode(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data.ID);
            }
        }

        if (!root)
            return root;

        root->height = 1 + max(Height(root->left), Height(root->right));
        int balance = Balance(root);

        /// LL
        if (balance > 1 && Balance(root->left) >= 0)
            return RightRotate(root);

        /// LR
        if (balance > 1 && Balance(root->left) < 0)
        {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }

        /// RR
        if (balance < -1 && Balance(root->right) <= 0)
            return LeftRotate(root);

        /// RL
        if (balance < -1 && Balance(root->right) > 0)
        {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }

        return root;
    }

    /// ===== DFS =====
    void InOrder(AVLNode* node)
    {
        if (!node)
            return;

        InOrder(node->left);
        cout << node->data.ID << " - "
             << node->data.Name << " - "
             << node->data.Age << endl;
        InOrder(node->right);
    }

    /// ===== Search =====
    AVLNode* Search(AVLNode* node, int id)
    {
        if (!node || node->data.ID == id)
            return node;

        if (id < node->data.ID)
            return Search(node->left, id);
        return Search(node->right, id);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void Insert(Employee emp)
    {
        root = Insert(root, emp);
    }

    void Delete(int id)
    {
        root = Delete(root, id);
    }

    void DFS()
    {
        InOrder(root);
    }

    Employee* Search(int id)
    {
        AVLNode* res = Search(root, id);
        return res ? &res->data : NULL;
    }

    Employee GetMinimum()
    {
        return MinNode(root)->data;
    }

    Employee GetMaximum()
    {
        AVLNode* cur = root;
        while (cur->right)
            cur = cur->right;
        return cur->data;
    }
};

#endif
