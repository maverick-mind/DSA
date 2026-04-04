#include<bits/stdc++.h>
using namespace std;
 
void printDecreasing(int n)
{
    // base case   // n ki kis value ke liye you will hit the base case 
    if(n == 0) return ; // return is mandatory in base case of void type
    // if(n == 1)
    // {
    //     cout<<n<<" ";
    //     return ;
    // }

    // recurrence relation
    // ek number print mai khud karunga , baaki sub-problem mera friend karega
    cout<<n<<" ";
    printDecreasing(n-1); // n hamesha ghat rha hai , so it will reach near base case in recurrence relation 

    return ; // optional

}
 
int main() 
{
    printDecreasing(10);
 
 
 
    return 0 ;
}