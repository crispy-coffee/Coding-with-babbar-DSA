#include <bits/stdc++.h>
using namespace std;

void margesort(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }

        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    } 

    while (i < n)
    {
        arr3[k] = arr1[i];
        cout << arr3[k] << " and " << arr1[i] << endl;
        k++;
        i++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
    for (int i = 0; i < (m + n); i++)
    {
        cout << "Print array : " << i << " " << arr3[i] << endl;
    }
}

int main()
{

    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[4] = {2, 4, 6, 8};
    int arr3[9] = {0};
    margesort(arr1, 5, arr2, 4, arr3);

    return 0;
}