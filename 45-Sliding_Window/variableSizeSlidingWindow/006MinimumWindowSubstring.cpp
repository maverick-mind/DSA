#include<bits/stdc++.h>
using namespace std;
 
bool isValid(unordered_map<char , int> & mp)
{   
    for(auto [key , freq] : mp)
    {
        if(freq > 0) return false ;
    }

    return true ;
}
 
int main() 
{
    string s = "dboaecbbdaeba";
    string t = "aabbbc"; // output : 8

    unordered_map<char , int> mp;

    for(int i = 0 ; i < t.size() ; i++)
    {
        mp[t[i]]++;
    }

    int minWindow = s.size() ;
    int n = s.size();

    int i = 0 ; 
    int j = 0 ; 

    while(j < n)
    {
       

        // expand the window 
        if(mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
        }
        j++;


        // shrink the window , if ith element does not matches with any element of the string t , do i++ to minimize the size of the window 
        while(mp.find(s[i]) == mp.end())
        {
            i++;
        }
        // also shrink the window if ith element freq is more than required 
        while(mp.find(s[i]) != mp.end() and mp[s[i]] < 0)
        {
            mp[s[i]]++;
            i++;
        }

         // does the current window satisfy the condition
        if(isValid(mp))
        {
            minWindow = min(minWindow , (j-i));
        }
    }
 
 
    cout<<minWindow<<endl;
    return 0 ;
}