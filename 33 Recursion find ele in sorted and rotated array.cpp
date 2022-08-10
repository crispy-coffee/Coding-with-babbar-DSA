
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findpivot(vector<int> &arr, int start, int end)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] < arr[0] && arr[mid - 1] > arr[mid])
        return mid;

    if (arr[mid] > arr[0])
        return findpivot(arr, mid + 1, end);

    else
        return findpivot(arr, start, end - 1);
}

int binarysearch(vector<int> &arr, int start, int end, int key)
{

    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
        return binarysearch(arr, mid + 1, end, key);
    else
        return binarysearch(arr, start, mid - 1, key);
}

int findPosition(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    if (arr.size() > 2)
    {

        int pivot = findpivot(arr, 0, n - 1);
        if (pivot == -1)
        {
            return binarysearch(arr, 0, n, k);
        }
        else
        {
            if (arr[0] <= k && k <= arr[pivot - 1])
                return binarysearch(arr, 0, pivot - 1, k);

            else
                return binarysearch(arr, pivot, n - 1, k);
        }
    }
    else
        return binarysearch(arr, 0, n, k);
}

int main()
{

    // vector<int> arr = {8, 10, 12, 15, 2};
    vector<int> arr = {2, 4, 5, 6, 7, 8};
    // vector<int> arr = {5 ,7 ,8 ,9 ,1 ,2 ,3 ,4};
    // vector<int> arr = {5};
    int n = 6;

    // int value = binarysearch(arr, 0, 2, 7);
    int value = findPosition(arr, n, 6);
    // int value = findpivot(arr, 0, 5);
    cout << value << endl;

    return 0;
}