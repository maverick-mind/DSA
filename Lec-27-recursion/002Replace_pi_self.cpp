#include<bits/stdc++.h>
using namespace std;
 
// inefficient or brute force O(n^2)
void fxn( string & s , int i)
{
    // base case 
    if(i+1 > s.size()) return ;

    // recurrence relation
    if(s[i] == 'p' and s[i+1] == 'i')
    {   s.erase(s.begin() + i, s.begin() + i+2);
        s.insert(i,"3.14");
    }
    fxn(s, i+1);
}
string replace_pi(string s , int i)
{
    // base case 
    if(i+1 > s.size()) return "";

    // recurrence relation
    string result = "";
    if(s[i] == 'p' and s[i+1] =='i')
    {
        result = result + "3.14" + replace_pi(s , i+2);
    }
    else{
        result =  result + s[i] + replace_pi(s , i+1) ;
    }

    return result ;
}
 
int main() 
{
    string s = "apibpicpi";
    // fxn(s , 0 );

    cout<<replace_pi(s,0);
    return 0 ;
}