#include<bits/stdc++.h>
using namespace std;
 

// time : O(2^n)
void fxn(int n , char src , char hlp , char dst )
{
    // base case 
    if( n == 0) // 0 disks ko move karna hai from source to destination 
    {
        return ; 
    }

    // recurrence relation 
    
    // 1. Ask your friend to move n - 1 disks from src (A) to hlp (B) using dst (c) 
    fxn(n-1 , src , dst , hlp);

    // 2. move the largest disks from src (A) to dst (C) 
    cout<<"move disk from "<< src << " to "<<dst <<endl;

    // 3. ask your friend to move n - 1 disks from hlp (B) to dst (C) using src (A)
    fxn(n-1 , hlp , src , dst);
}
 
int main() 
{
    int n = 3 ;

    fxn(n , 'A' , 'B' , 'C') ; // source --> 'A' , helper --> 'B' 
                             //  destination --> 'C'
 
    return 0 ;
}