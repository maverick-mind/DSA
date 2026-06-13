#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabacbebebe";
    int k = 3;

    unordered_map<char, int> mp; // <char , freq>

    int i = 0;
    int j = 0;
    int longestWindow = 0;

    while (j < s.size())
    { // for k unique characters , hashmap size must equals k

        // check if condition satisfy , when number of unique characters equals to k
        if (mp.size() == k)
        {
            longestWindow = max(longestWindow, (j - i + 1));
        }

        // expand the window , when number of unique characters is less than or equals to k 
        if (mp.size() <= k)
        {
            mp[s[j]]++;
            j++;
        }


        // shrink the window , when the number of unique characters is more than k
        while(mp.size() > k)
        {
            mp[s[i]]-- ;
            if(mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }

    }

    cout << longestWindow << endl;
    return 0;
}