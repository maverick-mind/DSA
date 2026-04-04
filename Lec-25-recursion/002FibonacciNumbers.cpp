#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    // base case 
    if( n == 0 or n == 1 )
    {
        return n ;
    }

    // recurrence relation 
    return f(n-1) + f(n-2);
 
}
 
 
int main() 
{
    
    cout<<f(2);
 
 
 
    return 0 ;
}