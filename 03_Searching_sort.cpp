#include <bits/stdc++.h>
using namespace std;

void SearchingSort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j; 
        }
        
        swap(arr[minIndex], arr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "The sorted array is " << arr[i] << endl;
    }
}

int main()
{

    int arr[5] = {2, 5, 15, 6, 3 };

    SearchingSort(arr, 5);
    // for (int i = 0; i <= 5; i++)
    // {
    //     cout << "The sorted array is " << arr[i] << endl;
    // }

    return 0;
}