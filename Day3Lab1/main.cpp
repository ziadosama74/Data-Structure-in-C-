///1- Implement Bubble Sort, Selection Sort and Merge Sort
///=======================================================
#include <iostream>
using namespace std;
#define     Bubble          1
#define     Selection       2
#define     merge           3
#define     SortAlg       merge
/// ==============================
/// ==    Function declaration  ==
/// ==============================
void DispalyArrayElement(int * arr,int Size);
void BubbleSortAlg(int * arr,int Size);
void SelectionSortAlg(int * arr,int Size);
/// ==============================================
void Merge(int* arr, int left, int mid, int right);
void MergeSortRec(int* arr, int left, int right);
void MergeSortAlg(int* arr, int Size);
/// ==============================
/// ==      Main Function       ==
/// ==============================
int main()
{
    #if  SortAlg == Bubble
    int MyArray[5] = {80,36,3,10,5};
    BubbleSortAlg(MyArray,5);
    DispalyArrayElement(MyArray,5);
    #elif SortAlg == Selection
    int MyArray[5] = {80,36,3,10,5};
    SelectionSortAlg(MyArray,5);
    DispalyArrayElement(MyArray,5);
    #elif SortAlg == merge
    int MyArray[5] = {80,36,3,10,5};
    MergeSortAlg(MyArray,5);
    DispalyArrayElement(MyArray,5);
    #endif
    return 0;
}
/// ==============================
/// ==    Function definition   ==
/// ==============================

/// Display Array
/// =============
void DispalyArrayElement(int * arr,int Size)
{
    for(int i = 0 ; i < Size ; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

/// Bubble Sort Algorithm
/// =====================
void BubbleSortAlg(int * arr,int Size)
{
    int Temp = 0 ;
    bool FlagSwap = false;
    for(int i = 0 ; i < Size ; i++)
    {
        for(int j = 0 ; j < Size - i - 1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                Temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = Temp;
                FlagSwap = true;
            }
            if(!FlagSwap)
            {
                break;
            }
        }
    }
}

/// Selection Sort Algorithm
/// ========================
void SelectionSortAlg(int *arr, int Size)
{
    for (int i = 0; i < Size - 1; i++)
    {
        int minIndex = i;
        /// Find smallest element in the remaining array
        for (int j = i + 1; j < Size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        /// Swap arr[i] with smallest element found
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
/// Merge Sort Algorithm
/// ====================
void Merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /// Copy any remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSortRec(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSortRec(arr, left, mid);      /// Left half
        MergeSortRec(arr, mid + 1, right); /// Right half

        Merge(arr, left, mid, right);      /// Merge
    }
}

void MergeSortAlg(int* arr, int Size)
{
    MergeSortRec(arr, 0, Size - 1);
}
