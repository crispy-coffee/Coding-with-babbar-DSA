#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool LinearSearch(int *arr, int size, int key){

    if(arr[0] == key){
        return true;
    }

    if(size == 0){
        return false;
    }

    return LinearSearch(arr+1, size-1, key);



}

int main(){

    int arr[] = {5,3,7,9,1,3,5};
    int n =7;
    int key; 
    cin >> key;
    bool result = LinearSearch(arr, n, key);
    cout << result <<endl;

return 0;
}