#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Bubblesort(int *arr, int n)
{

    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    Bubblesort(arr, n-1);

}

int main()
{

    int arr[5] = {5, 3, 1, 6, 7};

    Bubblesort(arr, 5);

    for(auto i: arr){
        // cout << "i : " << i <<endl;
        cout << i << " " ;
    }

    return 0;
}