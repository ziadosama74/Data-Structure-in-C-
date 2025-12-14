#include <iostream>
using namespace std;
#define  _Size      6
void QuickSort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);
void PrintArray(int arr[], int Size);

int main()
{
    int arr[_Size] = {10, 7, 8, 9, 1, 5};
    QuickSort(arr, 0, _Size - 1);
    PrintArray(arr, _Size);
    return 0;
}

/// ===============================
/// QuickSort Implementation
/// ===============================
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high); /// get the pivot index

        QuickSort(arr, low, pi - 1);        /// sort left sub-array
        QuickSort(arr, pi + 1, high);       /// sort right sub-array
    }
}

/// ===============================
/// Partition Function (Lomuto)
/// ===============================
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];  /// pivot = last element
    int i = low - 1;        /// index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            /// swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    /// place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1); /// pivot index
}

void PrintArray(int arr[], int Size)
{
    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
