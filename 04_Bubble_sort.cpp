#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int size)
{
    for (int i = 1; i < (size - 1); i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            swapped = true;
        }
        if (swapped == false)
            break;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "The sorted array is " << arr[i] << endl;
    }
}

int main()
{

    int arr[5] = {2, 5, 15, 6, 3};

    BubbleSort(arr, 5);
   
    return 0;
}