#include <bits/stdc++.h>
using namespace std;
#define ll long long

// vector<int> farNumber(int N, vector<int> &A)
// {
//     vector<int> solution;
//     int start = 0;
//     int last = N - 1;
//     while (start < N)
//     {

//         if (A[start] > A[last])
//         {
//             solution.push_back(last);
//             start++;
//             last = N - 1;
//         }
//         else if (start == last)
//         {
//             solution.push_back(-1);
//             if (start < N)
//             {
//                 start++;
//                 last = N - 1;
//             }
//             else
//                 break;
//         }
//         else if (A[start] < A[last])
//         {
//             if (start != last)
//                 last--;
//         }
//     }
//     return solution;
// }

void rearrange(vector<int> &arr)
{
    sort(arr, arr + n);
    int maxele = arr[n - 1];
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    int cnt = 0;
    for (int i = 0; i < maxele; i++)
    {
        if (s.find(i) == s.end())
            ++cnt;
        if (cnt == k)
            return i;
    }

    if (arr.size() <= 1)
        return;
    int s = 0;
    int l = 1;

    while (l <= arr.size())
    {
        cout << "fs gya bc " << endl;
        if (arr[s] > 0 && arr[l] <= 0)
        {
            swap(arr[s], arr[l]);
            s++, l++;
        }
        else if (arr[l] < 0)
        {
            l++;
        }
        else if (arr[s] > 0)
        {
            s++;
        }
    }
}

int main()
{

    // int t;
    // cin >> t;
    // while (t--)
    // {
    // }
    int n;
    cout << "Input de bhai" << endl;
    cin >> n;
    int input;
    vector<int> ans = {-1, 2, 2, -5};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> input;
    //     ans.push_back(input);
    // }

    rearrange(ans);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
