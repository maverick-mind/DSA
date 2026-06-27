#include<bits/stdc++.h>
using namespace std;
 
 
int main() 
{
    int n = 42 ;
    int k = 3 ;

    int mask = (1 << k) ; 

    (n & mask) == 0 ? cout<<"kth bit is 0"<<endl : cout<<"kth bit is 1"<<endl; // if kth bit is 1 , then (n & mask) would be 2^k


    // or 
    n = n >> k ; // now the kth bit is currently at 0th bit 
    (n & 1) == 0 ? cout<<"kth bit is 0"<<endl : cout<<"kth bit is 1"<<endl;


    return 0 ;
}