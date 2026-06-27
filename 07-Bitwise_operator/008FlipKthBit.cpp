#include<bits/stdc++.h>
using namespace std;
 
// if kth bit it 1 : make it 0
// if kth bit is 0 : make it 1
 
int main() 
{
    int n = 42 ;
    int k = 3 ; // output : 34 

    int mask = (1 << k) ; 

    cout<< (n ^ mask)<<endl;
 
 
 
    return 0 ;
}