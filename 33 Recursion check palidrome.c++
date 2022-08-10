#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool patliputra(string &binaryNum, int i, int j)
{
    if (i > j)
        return true;

    if (binaryNum[i] != binaryNum[j])
        return false;
    else
        return patliputra(binaryNum, i + 1, j - 1);
}

bool checkPalindrome(long long n)
{
    string binaryNum;
    int i = 0;
    while (n > 0)
    {
        binaryNum.push_back(n % 2);
        n = n / 2;
        i = i + 1;
    }
    int ans = patliputra(binaryNum, 0, binaryNum.length() - 1);
    if (ans == 1)
        return 1;
    else
        return 0;
}

int main()
{

    cout << checkPalindrome(11211);

    return 0;
}