#include<bits/stdc++.h>
using namespace std;
 
int fxn(int array[] , int n)
{
    // base case 
    if(n == 0 )
    {
        return 0 ;
    }

    // recursive case 
    int sum = 0 ;
    sum = array[n-1] + fxn(array , n-1);

    return sum ;

}
 
int main() 
{
    int array[] = {1,2,3,4,5};

    cout<<fxn(array , 5);
 
    return 0 ;
}