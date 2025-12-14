/// 6- Sort elements by frequency
/// =============================
#include <iostream>
using namespace std;
#define Size 5
/// ==============================
/// ==    Function declaration  ==
/// ==============================
void SortByFrequency(int *arr);
void DisplayArray(int *arr);

int main()
{
    int InputArr[Size] = {5, 5, 4, 6, 4};
    SortByFrequency(InputArr);
    DisplayArray(InputArr);
    return 0;
}

/// ==============================
/// ==  Function  Definition    ==
/// ==============================
void SortByFrequency(int *arr)
{
    /// find max value
    int maxVal = arr[0];
    for (int i = 1; i < Size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    /// frequency array
    int *freq = new int[maxVal + 1]{};

    /// count frequencies
    for (int i = 0; i < Size; i++)
        freq[arr[i]]++;

    /// sort based on frequency then value
    for (int i = 0; i < Size - 1; i++)
    {
        for (int j = i + 1; j < Size; j++)
        {
            bool needSwap = false;

            /// Higher frequency should come first
            if (freq[arr[j]] > freq[arr[i]])
                needSwap = true;

            /// If equal frequency → smaller element comes first
            else if (freq[arr[j]] == freq[arr[i]] && arr[j] < arr[i])
                needSwap = true;

            if (needSwap)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    delete[] freq;
}

void DisplayArray(int *arr)
{
    for (int i = 0; i < Size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
