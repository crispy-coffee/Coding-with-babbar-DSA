#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool BinarySearch(int arr[], int s, int e, int k)
{

    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return true;

    if (arr[mid] < k)
        return BinarySearch(arr, mid + 1, e, k);
    
    else 
        return BinarySearch(arr, s, mid-1, k);
}

int main()
{

    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int k, size = 8;
    cin >> k;

    bool finding = BinarySearch(arr, 0, size, k);
    cout << finding << endl;

    return 0;
}