#include <bits/stdc++.h>
using namespace std;
void movezero(int arr[], int n)
{

    int nonzero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonzero]);
            nonzero++;
        }
    }

    for (int j = 0; j < n; j++)
    {
        cout << "Value of " << j + 1 << " : " << arr[j] << endl;
    }
}

int main()
{

    int arr[7] = {1, 0, 0, 4, 0, 2, 4};

    movezero(arr, 7);

    return 0;
}