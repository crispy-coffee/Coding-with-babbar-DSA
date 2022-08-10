#include<bits/stdc++.h>
using namespace std;
#define ll long long

int power(int n){

    if(n == 0)
        return 1;

    return 2 * power(n-1);


}

int main(){

    int num;
    cin >> num;

    int ans = power(num);
    cout << ans << endl;

return 0;
}