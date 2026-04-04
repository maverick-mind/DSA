#include<bits/stdc++.h>
using namespace std ; 
 
bool isPalindrome(const string & str)// const& to avoid copy
{
     int start = 0 , end = str.size()-1;
            while(start < end)
            {     
                if(str[start] != str[end]) return false ;
                
                start++; end--;
            }
        return true ;
}

// time : O(n^3)
//space : O(1)
int countPallindromicSubstring(const string & s)// const& to avoid copy
{

    int count = 0 ;
    // substring banaao aur check karte jaao brute force se 
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string temp = s.substr(i , j-i+1);// substring nikaalo
            if(isPalindrome(temp)){
                count++;
            } 
        }
    }
    return count ;
}

int main() 
{
    string s = "abaaba"; // output : 11

    cout<<countPallindromicSubstring(s);
 
    return 0 ;
}