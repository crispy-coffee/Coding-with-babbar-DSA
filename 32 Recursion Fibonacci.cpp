#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fibonacci(int num)
{

    // base case
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;

    ll ans = fibonacci(num - 1) + fibonacci(num - 2);

    return ans;
}

int main()
{

    ll num;
    cin >> num;

    ll fb = fibonacci(num);
    cout << "Fibocci of " << num << " is " << fb << endl;

    return 0;
}