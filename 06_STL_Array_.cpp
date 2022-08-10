#include <bits/stdc++.h>
#include <array>
using namespace std;

int main()
{

    array<int, 4> ar = {1, 2, 2, 3};

    cout << ar.at(2) << endl;
    // int size = ar.size;
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << endl;
    }

    cout << ar.empty() << endl;
    cout << ar.front() << endl;
    cout << ar.back() << endl;

    return 0;
}