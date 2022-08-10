#include<bits/stdc++.h>
#include<set>

using namespace std;

int main(){

// set me same elements ko 1 hi element manta hai like 3 baar 5 input diya to set me 1 baar hi aayega 

set<int> s;


s.insert(3);
s.insert(2);
s.insert(4);
s.insert(5);
s.insert(6);
s.insert(7);
// begin()
// end()
// size()
// max_size()
// empty()
// erase(3)

// for print
for(auto i:s){
    cout << i << endl; 
}




return 0;
}