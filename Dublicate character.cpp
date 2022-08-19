#include <bits/stdc++.h>
using namespace std;
#define ll long long

void duplicate_char(string s, int n)
{
    /*
        vector<pair<char, int>> ans;
        sort(s.begin(), s.end());
        cout << s << endl;
        int count = 1;
        int i=0;
        for ( i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                count++;
            }

            // if (temp == true)
            // {
            // char c = s[i];
            // ans.push_back(make_pair(s[i],count));
            else
            {
                if (count > 1)
                {
                    cout << s[i] << " " << count << endl;
                    count = 1;
                    // temp == false;
                }
            }
            // }
        }
        if (count > 1)
        {
            cout << s[i] << " " << count << endl;
            count = 1;
            // temp == false;
        }

        // return ans;
        */

    // vector<pair<char, int>> duplicate_char(string s, int n)
    {
        vector<pair<char, int>> ans;
        int arr[256] = {0};
        for (int i = 0; i < n; i++)
        {
            arr[s[i]]++;
            cout << s[i] << " " << arr[s[i]]++ << endl; 
        }
        cout << "fanu" << endl;
        for (int i = 0; i < 256; i++)
        {
            if (arr[i] > 1)
            {
                ans.push_back({i, arr[i]});
                cout << i << " " << arr[i] << endl;
            }
        }
        // return ans;
    }
}

int main()
{

    string s = "DEVENDER";
    int n = 8;
    duplicate_char(s, n);

    return 0;
}