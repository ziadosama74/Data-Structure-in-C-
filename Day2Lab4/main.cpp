#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack *SK = new Stack(4);
    SK->Push(1);
    SK->Push(3);
    SK->Push(2);
    SK->Push(4);
    SK->Display();
    int * MyArr = SK->Next_Greater_Element();
    for(int i = 0 ; i < 4 ; i++)
    {
        cout << MyArr[i] << "\t";
    }

}
