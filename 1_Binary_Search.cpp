#include <bits/stdc++.h>
using namespace std;

int Binarysearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }


        // right wali side chale jao
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        // left wali side chale jao
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{

    int even[6] = {2, 3, 5, 6, 7, 8};
    int odd[5] = {1, 2, 4, 6, 7};

    int evenIndex = Binarysearch(even, 6, 8);
    cout << "Index of 8 is " << evenIndex << endl;

    int oddIndex = Binarysearch(odd, 5, 7);
    cout << "Index of 4 is " << oddIndex << endl;

    return 0;
}