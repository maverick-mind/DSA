#include<bits/stdc++.h>
using namespace std;
 
// time : O(log y)
// space : O(logy)
int f(int x , int y)
{
    // base case 
    if(y == 0)
    {
        return 1 ;
    }

    // recurrence relation
    int A = f(x , y/2) ; // save the result and then return , based on y is even or odd 
    if(y % 2 == 0) // y is even
    {
        // x^y = x^(y/2) * x^(y/2)         
        return A*A ;
    }
    else{
        // y is odd 
        // x^y = x^(y/2) * x^(y/2) * x ;
        return A * A * x ;
    }
}

int main() 
{
    cout<<f(3,4);
 
 
 
    return 0 ;
}