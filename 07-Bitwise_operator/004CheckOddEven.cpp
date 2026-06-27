#include<bits/stdc++.h>
using namespace std;
 
// for all odd number : lsb is 1 
// for all even number : lsb is 0 
 
int main() 
{
    int n = 11 ; // when lsb is 1 then odd , so take bitwise & 

    (n & 1) == 0 ? cout<<"even" : cout<<"odd" ;
 
 
    return 0 ;
}