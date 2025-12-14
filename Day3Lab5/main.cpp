/// 5- Sort the given matrix
/// ========================
#include <iostream>
using namespace std;
#define       R     3
#define       C     3
#define       S   (R * C)
/// ==============================
/// ==    Function declaration  ==
/// ==============================
void Display2DArray(int arr[][C]);
void BubbleSortAlg(int * arr, int Size);
void Sort2DArray(int arr[][C]);
/// ==============================
int main()
{
    int _2DArray[R][C] =
    {
        {5, 4, 7},
        {1, 3, 8},
        {2, 9, 6}
    };
    cout << "Original 2D Array:\n";
    Display2DArray(_2DArray);
    Sort2DArray(_2DArray);
    cout << "2D Array after Sorting:\n";
    Display2DArray(_2DArray);
    return 0;
}

/// ==============================
/// ==  Function  Definition    ==
/// ==============================
void Display2DArray(int arr[][C])
{
    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void BubbleSortAlg(int * arr, int Size)
{
    int Temp = 0;

    for(int i = 0 ; i < Size ; i++)
    {
        bool FlagSwap = false;

        for(int j = 0 ; j < Size - i - 1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                Temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = Temp;
                FlagSwap = true;
            }
        }

        if(!FlagSwap)
            break;
    }
}

void Sort2DArray(int arr[][C])
{
    int _1DArr[S];
    int index = 0;
    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ; j++)
        {
            _1DArr[index++] = arr[i][j];
        }
    }
    BubbleSortAlg(_1DArr, S);
    index = 0;
    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ; j++)
        {
            arr[i][j] = _1DArr[index++];
        }
    }
}

