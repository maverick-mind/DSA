#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n = 42 ; // total set bits : 3 

    int setbits = 0 ; 

    while(n != 0)
    {
        int lsb = (n & 1) ;

        lsb == 1 ? setbits++ : setbits ;

        n >>= 1 ;
    }

    cout<<setbits;
 
 
 
    return 0 ;
}