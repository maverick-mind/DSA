#include<bits/stdc++.h>
using namespace std;
 
int factorial(int n)
{
    // base case 
    if(n == 0 or n == 1)
    {
        return 1 ;
    }

    // Recurrence Relation must be a sub-problem , har recursive call mein problem ka size kam hona chahiye
    else {
        return n * factorial(n-1);
    }

}

 
int main() 
{
    int n = 5 ;
    cout<<factorial(5)<<endl;
    
    return 0 ;
}