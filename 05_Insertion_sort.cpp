#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int size)
{
    fo
    r (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >=0; j--)
        {
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break; 
            }
        }
        arr[j+1] = temp;
       
    }

    for (int i = 0; i < size; i++)
    {
        cout << "The sorted array is " << arr[i] << endl;
    }
}

int main()
{

    int arr[5] = {2, 5, 15, 6, 3};

    InsertionSort(arr, 5);
   
    return 0;
}