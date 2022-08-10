#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s <= e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6};
    vector<int> ans;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    { 

        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;     // generates carry
        int value = sum % 10; // simply store the last digit of the sum
        ans.push_back(value);
        i--;
        j--;
    }

    // first case, if first vector is lenthy;
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;     // generates carry
        int value = sum % 10; // simply store the last digit of the sum
        ans.push_back(value);
        i--;
    }

    // second case if second vector is lengthy
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;     // generates carry
        int value = sum % 10; // simply store the last digit of the sum
        ans.push_back(value);
        j--;
    }

    // if carry left??
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        int value = sum % 10;
        ans.push_back(value);
    }

    // reverse(ans);

    // hum ya to loop ulta chala skte hai , ya reverse kr skte hai vector ko reverse function se
    for (int i = ans.size()-1; i >=0 ; i--)
    {
        cout << "Value of " << i << " :" << ans[i] << endl;
    }
    return 0;
}