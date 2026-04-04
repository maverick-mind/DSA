#include<bits/stdc++.h>
using namespace std;
 
// time : O(y)
// space : O(y)
int f(int x , int y)
{
    // base case 
    if(y == 0 )
    {
        return 1 ;
    }

    // reccurence relation
    // ek multiply mai khud karunga , y-1 times multiply mera friend karega
    return x * f(x,y-1);
}
 
int main() 
{
    int x = 2 , y = 3 ; // x^y
    cout<<f(x,y);
 
 
 
    return 0 ;
}