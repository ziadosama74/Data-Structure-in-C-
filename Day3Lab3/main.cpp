#include <iostream>
using namespace std;

#define Enable      1
#define Disable     0
#define Recursion Disable

/// ==============================
/// ==    Function declaration  ==
/// ==============================
int Binary_Search_iteratively(int * arr, int Size, int Val);
int Binary_Search_recursively(int * arr, int left, int right, int Val);

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int Size = sizeof(arr) / sizeof(arr[0]);
    int Val = 70;
    #if Recursion == Enable
        cout << "Recursive Result: " << Binary_Search_recursively(arr, 0, Size - 1, Val) << endl;
    #else
        cout << "Iterative Result: " << Binary_Search_iteratively(arr, Size, Val) << endl;
    #endif
    return 0;
}

/// =======================================================
/// =             Iterative Version                       =
/// =======================================================
int Binary_Search_iteratively(int * arr, int Size , int Val)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == Val)
            return mid;

        else if (arr[mid] < Val)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

/// =======================================================
/// =             Recursive Version                       =
/// =======================================================
int Binary_Search_recursively(int * arr, int left, int right, int Val)
{
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == Val)
    {
        return mid;
    }
    else if (arr[mid] < Val)
    {
        return Binary_Search_recursively(arr, mid + 1, right, Val);
    }
    else
    {
        return Binary_Search_recursively(arr, left, mid - 1, Val);
    }
}
