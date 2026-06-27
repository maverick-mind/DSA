#include<bits/stdc++.h>
using namespace std;
 
// make kth bit as 0 
// if 1 : make it 0 
// if 0 : leave it 
 
int main() 
{
    int n = 42 ; 
    int k = 3 ; // output : 34 


    int mask = ~(1 << k) ; // kth bit 0 , rest other bit as 1 
    cout<< (n & mask)<<endl;

 
 
 
    return 0 ;
}