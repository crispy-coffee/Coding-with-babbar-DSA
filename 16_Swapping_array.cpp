#include<bits/stdc++.h>
#include<vector>

using namespace std;

void reverse(vector<int> &arr, int m){

    int s=m+1, e=arr.size()-1;

    while(s<=e){

        swap(arr[s],arr[e]);
        s++;
        e--;

    }

    for(int i =0;i<arr.size();i++){
        cout <<arr[i] << " ";
    }

}

int main(){

    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);

    reverse(v, 2);

return 0;
}