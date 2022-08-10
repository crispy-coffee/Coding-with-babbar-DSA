#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isSorted(int arr[], int size){

    //base case 
    if(size == 0 || size == 1)
        return true;


    if(arr[0] < arr [1])
        return isSorted(arr+1, size-1);
    
    else
        return false;

}


int main()
{

    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int size = 8;

    bool finding = isSorted(arr, size);
    cout << finding << endl;

    return 0;
}