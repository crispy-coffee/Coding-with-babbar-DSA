#include <bits/stdc++.h>
using namespace std;

int FirstOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans=0;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid-1;

        }


        // right wali side chale jao
        else if (key > arr[mid])
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
    return ans;
}

int LastOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans=0;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid+1;

        }


        // right wali side chale jao
        else if (key > arr[mid])
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
    return ans;
}
int main()
{

    int even[6] = {2, 3, 5, 5, 5, 8};

    int evenIndex = FirstOccurence(even, 6, 5);
    cout << "Index of 8 is " << evenIndex << " Last Occurence is " << LastOccurence(even, 6, 5) << endl;



    return 0;
}