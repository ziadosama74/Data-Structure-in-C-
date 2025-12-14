#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
using namespace std;
class LinkedList
{
    public:
        LinkedList()
        {
            head = tail = NULL;
        }
        void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);

            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;

            }
            else
            {

                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
        }
        // for testing
        void Display()  // O(n)
        {
            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"\t";

                //move next
                current = current->next;
            }
            cout << endl;
        }
        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }
        bool DeleteByIndex(int index,int * Ret_Value)
        {
            Node * node = head;
            if(node != NULL)
            {
                int i = 0 ;
                while (node != NULL && i < index)
                {
                    node = node->next;
                    i++;
                }
                *Ret_Value = node->data;
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }
                /// head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }
                /// tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }
                /// in between
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }
                delete node;
                return true;
            }
            else return false;
        }
        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;

            }
            else return false;
        }
        bool DeleteFromFirst(int * Ret_val)
        {
            if (head == NULL)
                return false;
            Node* First = head;
            *Ret_val = First->data;
            if (head == tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
            }
            delete First;
            return true;
        }
    private:
        Node * head;
        Node * tail;

    Node* getNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
                return current;
            //move next
            current = current->next;
        }
        return NULL;
    }
};

#endif // LINKEDLIST_H
