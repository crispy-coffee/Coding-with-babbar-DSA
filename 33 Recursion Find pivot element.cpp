#include<bits/stdc++.h>
using namespace std;
#define ll long long

findpivot(vector<int>& arr, int start, int end){
    
    if(start>end)
        return -1;

    int mid = start + (end - start)/2;
    
    if(arr[mid] < arr[0] && arr[mid-1] > arr[mid])
        return mid;
    
    if(arr[mid] > arr[0])
        return findpivot(arr, mid + 1, end);
    
    else
        return findpivot(arr, start , end-1);
    
}

int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    
    return findpivot(arr, 0, n-1 );
    
}



int main(){

    vector<int> arr = {8, 4, 6};
    int n = 3;

    int value = findPosition(arr, n, 0);
    cout << value << endl;

return 0;
}