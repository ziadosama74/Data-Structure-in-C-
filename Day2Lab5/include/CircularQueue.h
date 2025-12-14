#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include <iostream>
using namespace std;  // أو استخدم std::cout و std::endl

class CircularQueue
{
    private:
        int Front;
        int Rear;
        int Count;
        int Size;
        int * QueArr;
        bool ISEmpty()
        {
            return (Count == 0);
        }
        bool ISFull()
        {
             return (Count == Size);
        }
    public:
        CircularQueue(int S)
        {
            Front = Rear = -1;
            Count = 0;
            Size = S;
            QueArr = new int[Size];
        }
        /// Enqueue Function
        /// ================
        bool Enqueue(int _data)
        {
            if (ISFull())
                return false;

            if (ISEmpty())
                Front = 0;

            Rear++;
            if (Rear == Size)
                Rear = 0;

            QueArr[Rear] = _data;
            Count++;
            return true;
        }
        /// Dequeue Function
        /// ================
        bool Dequeue()
        {
            if (ISEmpty())
            return false;

            QueArr[Front] = -1;
            Front++;
            if (Front == Size)
                Front = 0;

            Count--;
            return true;
        }
        /// Display Function
        /// ================
        void Display()
        {
            if (ISEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                int i = Front;
                int printed = 0;
                while (printed < Count)
                {
                    cout << QueArr[i] << "\t";
                    i++;
                    if (i == Size)
                        i = 0;
                    printed++;
                }
                cout << endl;
            }
        }
        /// Reverse Queue
        /// =============
        void Reverse()
        {
            if (ISEmpty())
                return;

            /// Step 1: Copy elements into temp array
            int *temp = new int[Count];
            int index = 0;

            int i = Front;
            int printed = 0;

            while (printed < Count)
            {
                temp[index] = QueArr[i];
                index++;
                i++;
                if (i == Size)
                    i = 0;
                printed++;
            }
            /// Step 2: Put reversed elements back
            Front = 0;
            Rear = Count - 1;

            for (int i = 0; i < Count; i++)
                QueArr[i] = temp[Count - i - 1];

            delete[] temp;
        }

};

#endif // CIRCULARQUEUE_H
