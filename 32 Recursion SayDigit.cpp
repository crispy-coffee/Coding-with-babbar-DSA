#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sayDigit(string *arr, int number)
{

    if (number == 0)
        return;

    int digit = number % 10;
    number = number / 10;

    sayDigit(arr, number);
    cout << arr[digit] << " ";
}

int main()
{

    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int number;
    cin >> number;
    // cout << 432%10 << endl;
    // cout << 2 / 10;
    sayDigit(arr, number);

    return 0;
}