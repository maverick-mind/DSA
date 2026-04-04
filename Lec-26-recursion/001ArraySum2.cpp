#include<bits/stdc++.h>
using namespace std;
 
// array is just passed as pointer , so we cannot do sizeof(array)/sizeof(int) , it will give error 
int fxn(int array[] , int n , int i)
{
    // base case 
    if(i == n)
    {
        return 0 ;
    }
    // recurrence relation
    int ans = array[i] + fxn(array , n , i+1);

    return ans ;
}
 
int main() 
{
    int array[] = {1,2,3,4,5};
    cout<<fxn(array , 5 , 0);
 
    return 0 ;
}