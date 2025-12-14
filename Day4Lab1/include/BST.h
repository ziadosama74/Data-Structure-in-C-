#ifndef BST_H
#define BST_H
#include "Node.h"
#include "Employee.h"

class BST
{
private:
    Node* root;

    /// ================= INSERT =================
    Node* Insert(Node* node, Employee emp)
    {
        if (node == NULL)
            return new Node(emp);

        if (emp.ID < node->data.ID)
            node->left = Insert(node->left, emp);
        else if (emp.ID > node->data.ID)
            node->right = Insert(node->right, emp);

        return node;
    }

    /// ================= DFS (INORDER) =================
    void InOrder(Node* node)
    {
        if (node == NULL)
            return;

        InOrder(node->left);
        cout << node->data.ID << " - "
             << node->data.Name << " - "
             << node->data.Age << endl;
        InOrder(node->right);
    }

    /// ================= SEARCH =================
    Node* Search(Node* node, int id)
    {
        if (node == NULL || node->data.ID == id)
            return node;

        if (id < node->data.ID)
            return Search(node->left, id);
        else
            return Search(node->right, id);
    }

    /// ================= GET MIN =================
    Node* GetMin(Node* node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    /// ================= GET MAX =================
    Node* GetMax(Node* node)
    {
        while (node && node->right != NULL)
            node = node->right;
        return node;
    }

    /// ================= DELETE (ALL CASES) =================
    Node* Delete(Node* node, int id)
    {
        if (node == NULL)
            return NULL;

        if (id < node->data.ID)
            node->left = Delete(node->left, id);

        else if (id > node->data.ID)
            node->right = Delete(node->right, id);

        else
        {
            ///  Case 1: Leaf node
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            /// case 2: One child
            else if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            /// Case 3: Two children
            Node* successor = GetMin(node->right);
            node->data = successor->data;
            node->right = Delete(node->right, successor->data.ID);
        }

        return node;
    }

public:
    BST()
    {
        root = NULL;
    }

    void Insert(Employee emp)
    {
        root = Insert(root, emp);
    }

    void DFS()
    {
        InOrder(root);
    }

    Employee* Search(int id)
    {
        Node* result = Search(root, id);
        if (result)
            return &result->data;
        return NULL;
    }

    Employee GetMinimum()
    {
        Node* minNode = GetMin(root);
        return minNode->data;
    }

    Employee GetMaximum()
    {
        Node* maxNode = GetMax(root);
        return maxNode->data;
    }

    void Delete(int id)
    {
        root = Delete(root, id);
    }
};


#endif // BST_H
