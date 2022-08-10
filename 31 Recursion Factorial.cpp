#include<bits/stdc++.h>
using namespace std;
#define ll long long

int factorial(int num){

    if(num == 0)
        return 1;

    return num*factorial(num-1);


}

int main(){

    
    int num;
    cin >> num;
    ll fac = factorial(num);
    cout << "The factorial of " << num << " is " << fac << endl;


return 0;
}