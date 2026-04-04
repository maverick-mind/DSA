#include<bits/stdc++.h>
using namespace std;
 
void fxn(string s , int i , string & ans )
{
    // base case 
    if(s[i] == '\0')
    {
        cout<<ans<< " , ";
        return ;
    } 

    // to generate a subsequence , you have to take a sequence of 'n' decisions , a decision for each character in the input , whether to INCLUDE it or EXCLUDE it from the output we are trying to build 

    // jab bhi koi question solve kar rhe hai , aur uss question ko solve karte time you realise ki iss ko solve karne ke liye , I have to take a sequence of decisions and suppose aapse kahaa gya ki design a recursive algorithm for this , all you have to do is take a first decision , baaki decisions can be taken recursively 

    // recurrence relation
    // // inclusion
    // ans += s[i] ;
    // fxn( s , i+1 , ans);
        // ans.pop_back(); // baktracking

    // // exclusion
    // fxn(s , i+1 , ans );

    
    // exclusion
    fxn(s , i + 1 , ans);

    // inclusion 
    ans += s[i] ;
    fxn(s , i + 1 , ans);
    ans.pop_back(); // backtracking 




}
 
int main() 
{
    string s = "abc";
    string ans = "";
    fxn( s , 0 , ans );

     
 
 
 
    return 0 ;
}