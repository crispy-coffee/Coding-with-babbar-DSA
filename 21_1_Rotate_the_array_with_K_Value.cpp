#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {2, 3, 4, 5, 6, 7};
    vector<int> temp(v.size());
    int k = 2;
    for (int i = 0; i < v.size(); i++)
    {
        temp[(i + k) % v.size()] = v[i];
    }

    for (int i = 0; i < temp.size(); i++)
    {
        cout << "Value of " << i << " :" << temp[i] <<endl;
    }
    return 0;
}