#ifndef AVLNODE_H
#define AVLNODE_H

#include "Employee.h"

class AVLNode
{
public:
    Employee data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Employee emp)
    {
        data = emp;
        left = right = NULL;
        height = 1;
    }
};

#endif
