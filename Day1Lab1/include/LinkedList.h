#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    private:
    Node * head;
    Node * tail;
    int Count_Node = 0;
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
    public:

        LinkedList()
        {
            head = tail = NULL;
        }
        Node * Gethead()
        {
            return head;
        }
        Node * Gettail()
        {
            return tail;
        }
        /// insert end of list
        /// ==================
        void insertEnd(int data)  // O(1)
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
            Count_Node++;

        }
        /// Display list
        /// ============

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
        }
        /// Search list
        /// ============
        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }

        /// Delete node
        /// ============
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
                Count_Node--;
                delete node;

            }
            else return false;
        }
        /// insert node after
        /// =================
        void insertAfter(int data,int afterData)
        {
            Node * StandNode = getNode(afterData);
            if(StandNode != nullptr && StandNode != tail && StandNode && head )
            {
                Node * node = new Node(data);
                node->next = (StandNode->next);
                node->prev = StandNode;
                (StandNode->next)->prev = node;
                StandNode->next = node;
                Count_Node++;
            }
        }
        /// insert node before
        /// ==================
        void insertBefore(int data,int beforData)
        {
            Node * StandNode = getNode(beforData);
            if(StandNode != nullptr && StandNode != tail && StandNode && head )
            {
                Node * node = new Node(data);
                node->next = StandNode;
                node->prev = StandNode->prev;
                (StandNode->prev)->next = node;
                StandNode->prev = node;
                Count_Node++;
            }
        }
        /// Get number of nodes
        /// ===================
        int Get_Nodes_Number()
        {
            return Count_Node;
        }
        ///  reverse list in place
        /// ======================
        void Reverse()
        {
            Node * First = head;
            Node * Last = tail;
            int Temp = 0;
            while (First != Last && First->prev != Last)
            {
                Temp = First->data;
                First->data = Last->data;
                Last->data = Temp;
                First = First->next;
                Last = Last->prev;
            }
        }
        ///  get Data by index
        /// ======================
        int getDataByIndex(int index)
        {
            if (index < 0 || index >= Count_Node){return -1;}
            Node* current = head;
            int Itrator = 0;
            while (current != NULL && Itrator < index)
            {
                current = current->next;
                Itrator++;
            }
            if (current != NULL)
            {
                return current->data;
            }
            else{return -1;}
        }
        /// Remove every k-th node of the linked list
        /// =========================================
        void Remove_Every_K_th(int k)
        {
            if (k >= 0)
            {
               Node* current = head;
               int i = 1;
               while (current != NULL)
                {
                    Node* nextNode = current->next;
                    if (i % k == 0)
                    {
                        Delete(current->data);
                    }
                current = nextNode;
                i++;
               }
            }
        }
        /// intersection of Two Sorted Linked Lists
        /// =======================================
        LinkedList* Intersection(LinkedList* other)
        {
            LinkedList* result = new LinkedList();
            Node* current1 = head;
            while (current1 != NULL)
            {
                Node* current2 = other->head;
                while (current2 != NULL)
                {
                    if (current1->data == current2->data)
                    {
                        result->insertEnd(current1->data);
                        break;
                    }
                    current2 = current2->next;
                }
                current1 = current1->next;
            }
            return result;
        }

};

#endif // LINKEDLIST_H
