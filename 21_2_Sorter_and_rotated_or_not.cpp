#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {3, 4, 5, 6, 7, 3, 2};

    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            count++;
        }
    }

    if (v[v.size() - 1] > v[0])
    {
        count++;
    }

    if (count <= 1)
    {
        cout << "Sorted and rotated";
    }
    else
    {
        cout << "NOt";
    }

    return 0;
}