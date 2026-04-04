#include<bits/stdc++.h>
using namespace std;
 
int f(int a , int b)
{
    // base case
    if(a == 0)
    {
        return 0 ;
    }

    // recurrence relation 
    return b + f(a-1 , b) ;

}
 
int main() 
{
    cout<<f(4,5);
    
 
 
 
    return 0 ;
}