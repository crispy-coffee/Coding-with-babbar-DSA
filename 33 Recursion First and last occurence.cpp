#include <bits/stdc++.h>
using namespace std;
#define ll long long



int firstoccurence(int *arr, int start, int end, int key, int ans)
{

    if (start > end)
        return ans;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        ans = mid;
        end = mid - 1;
    }
   
    if (arr[mid] >= key)
        return firstoccurence(arr, start, mid-1, key, ans);
    else
        return firstoccurence(arr, mid+1, end, key, ans);
}

int lastoccurence(int *arr, int start, int end, int key, int ans)
{

    if (start > end)
        return ans;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        ans = mid;
        start = mid + 1;
    }


    if (arr[mid] <= key)
        return lastoccurence(arr, mid+1, end, key, ans);
    else
        return lastoccurence(arr, start, mid-1, key, ans);
}

int main()
{

    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};   
    int n = 8;
    int k = 2;
    pair<int, int> s;
    s.first = firstoccurence(arr, 0, n - 1, k, -1);
    s.second = lastoccurence(arr, 0, n - 1, k, -1);
    cout << s.first << endl;
    cout << s.second << endl;

    return 0;
}