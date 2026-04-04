#include<bits/stdc++.h>
using namespace std;
 
// move from right to left 
void fxn(string & s , int i)
{
    // base case 
    if(i == 0)
    {
        if(s[i] == 'x')
        {
            s.erase(i,1) ; // erase part of string starting at index i and of length 1 
            s.push_back('x');
        }
        return  ;
    }

    // recurrence relation 
    if(s[i] == 'x')
    {
        s.erase(i,1);
        s.push_back('x');
    }
    fxn(s,i-1);
    // return s ;

}
 
int main() 
{
    string s = "xaxbxc";

    fxn(s,s.size()-1);

    cout<<s<<endl;
 
 
 
    return 0 ;
}