#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{

    // ye python ki dictionary ki tarah same hi hai wahi key and walue
    map<int, string> m; // key and value // value can be same but key not;

    m[1] = "Dev";
    m[10] = "verma";
    m[2] = "Dd";

    for (auto i : m)
    {
        cout << i.first << endl;  // first will print the key
        cout << i.second << endl; // seconf will print the value
    }

    m.erase(10);
    for (auto i : m)
        cout << i.first << endl;

    auto it = m.find(2); //agr 2 exist krta hai to 2 return kr dega simple

    cout << "hello " <<endl;
    for(auto i = it; i!=m.end();i++){
        cout << (*i).first << endl;
    }

    return 0;
}