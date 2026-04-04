#include<bits/stdc++.h>
using namespace std;
 
void printIncreasing(int n)
{
    // base case 
    if(n == 0) return ;
    // if(n == 1)
    // {
    //     cout<<1<<" ";
    //     return ;
    // }

    // recurrence relation
    else{
        printIncreasing(n-1); // n hamesha ghat rha hai , so it will reach near base case in recurrence relation 
        cout<<n<<" ";
    }

    return ; // optional
} 


int main() 
{
    printIncreasing(10);
 
 
    return 0 ;
}