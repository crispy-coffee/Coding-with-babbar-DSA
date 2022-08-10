#include <bits/stdc++.h>
using namespace std;
#define ll long long

int getSum(int *arr, int n){

    if(n == 1)
        return arr[0];

    // if(n == 0)
    //     return 0;

    
    return arr[0] + getSum(arr+1, n-1);


}

int main()
{

    int arr[] = {5, 3, 6, 7, 8, 91, 3};
    int n = 7;
    int sum =0;
    ll sumo = getSum(arr, n);
    cout << sumo << endl;

    return 0;
}