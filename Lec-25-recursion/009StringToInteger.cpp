// convert string to integer 
#include<bits/stdc++.h>
using namespace std;
 

// time : s.size() * n(due to linear time of substring extraction )
// time : O(n*n) --> O(n^2)
// space : O(n^2) --> n stack frames hai , aur harr stack frame ke pass ek khud ka subString hai , uss ka size n hoga at max 
int f(string s , int n)
{
    // base case 
    if(n == 0) // s.empty() // s == ""
    {
        return 0 ; 
    }
    // base case 
    // if(n == 1)
    // {
    //     return int(s[n-1] - '0') ; 
    // }

    // reccurence relation

    // f(s) : convert string s to integer

    // // 1. ask your friend to convert the substring that starts
	// at index 0 and has a length n-1 to an integer

    string subString = s.substr(0 , n) ;
    int integerFromMyFriend = f( subString , n - 1);

    return integerFromMyFriend * 10 + (s[n-1] - '0');


}
 
int main() 
{
    string s = "345621" ;
    cout<<f(s , s.size()) + 10;
    // cout<<3 + ('4' - '0');
 
    return 0 ;
}