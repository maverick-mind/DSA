#include<bits/stdc++.h>
using namespace std ; 
 
 
int main() 
{
    char ch= 'A';

    char * p = &ch ;

    int * ptr = (int*)&ch ; // jo ptr hai wo int* type ka hai , issliye &ch ka typecasting (int*) mein hona chhaiye
    cout<<ptr;

 
 
 
    return 0 ;
}