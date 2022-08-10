#include<bits/stdc++.h>
using namespace std;
#define ll long long



int peakele(vector<int> &arr, int start, int end)
{

    int mid = start + (end - start) / 2;

    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        return mid;

    cout << " hello " << endl;

    if (arr[mid - 1] < arr[mid])
        return peakele(arr, mid , end);
    else
        return peakele(arr, start, mid);
}

int peakIndexInMountainArray(vector<int> &arr)
{

    return peakele(arr, 0, arr.size() - 1);

}

int main(){

    vector<int> arr = {3,5,3,2,0};

    int value = peakIndexInMountainArray(arr);
    cout << value << endl;

return 0;
}
