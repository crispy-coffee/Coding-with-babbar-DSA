#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{   
    // vector is dynamin

    vector<int> v;
    // element daal rhe hai piche se aur piche se hi dalta hai isme
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // piche se 1 element nikal dega ye
    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    cout << v.capacity() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.empty() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}