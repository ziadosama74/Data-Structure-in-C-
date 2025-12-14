#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

class Stack
{
    public:
        // array
        int stackSize;
        int top;
        int *arr;

        Stack(int _stackSize)
        {
            this->stackSize = _stackSize;

            arr = new int[stackSize];
            // last filled cell
            top = -1;
        }

        bool Push(int val)
        {
            // O(1)
            // if stack full
            if(ISFull())
                return false;

            else
            {
                top++;
                arr[top] = val;
                return true;
            }

        }

        bool Pop(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;

            val = arr[top];
            --top;
            return true;
        }

        bool Peek(int &val)
        {
            //o(1)
            if(IsEmpty())
                return false;
            val = arr[top];
            return true;

        }

        void Display()
        {
            for(int i = 0 ; i < top + 1 ; i++)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
        /// ==========================
        int* Next_Greater_Element()
        {
            int* RetArr = new int[top + 1];

            for(int i = 0; i <= top; i++)
            {
                RetArr[i] = -1;
                for(int j = i + 1; j <= top ; j++)
                {
                    if(arr[j] > arr[i])
                    {
                        RetArr[i] = arr[j];
                        break;
                    }
                }
            }

            return RetArr;
        }


    protected:

    private:
        bool ISFull()
        {
            return top == stackSize - 1;
        }


        bool IsEmpty()
        {
            return top == -1;
        }
};

#endif // STACK_H
