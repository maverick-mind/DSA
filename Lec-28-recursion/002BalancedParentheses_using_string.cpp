#include<bits/stdc++.h>
using namespace std;
 
void fxn(string str , int open , int close , int n )
{
    // base case 
    if(open == n and close == n)
    {
        cout<<str<<endl;
        return ;
    }

    // recurrence relation
    if(open < n)
    {
        str += '(';
        fxn(str , open + 1 , close , n);
        str.pop_back();
    }
    if(close < open)
    {
        str += ')';
        fxn(str , open , close + 1 , n) ; 
        str.pop_back() ;
    }
}
 
int main() 
{
    int n = 2 ;
    string str = "";
    fxn(str , 0 , 0 , n);
 
 
 
    return 0 ;
}