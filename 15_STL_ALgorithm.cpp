#include <bits/stdc++.h>
// #include <algorithm>
// #include <vector>

using namespace std;

int main()
{

    vector<int> v;

    //Vector must be sorted for binary search
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    cout << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Lower bournd of 6 : " <<lower_bound(v.begin(), v.end(),6)-v.begin() << endl;
    cout << "Upper Bound of 6 :" <<upper_bound(v.begin(), v.end(),6)-v.begin() << endl;
    return 0;
}